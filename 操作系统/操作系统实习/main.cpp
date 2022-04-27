#include "PageManager.h"
#include <assert.h>
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <vector>
using std::vector;

static const int NUM = 400;
sem_t blank_num, pro_num; // signal varible
pthread_mutex_t mutex;    // muetx
int cur = -1;             // current point in order vector
int INT = 0;              // INT count
PageManager p;
vector<Page> order; // our_storage
int choose = 0;

// four page exchange function pointer
vector<bool (PageManager::*)(int num)> func;
bool (PageManager::*f1)(int num) = &PageManager::OPT;
bool (PageManager::*f2)(int num) = &PageManager::FIFO;
bool (PageManager::*f3)(int num) = &PageManager::LRU;
bool (PageManager::*f4)(int num) = &PageManager::CLOCK;

void showMessage() {
    std::cout << "RAM size = " << p.get_RAM_Size() << std::endl;
    std::cout << "[-1]: change_RAM_SIZE" << std::endl;
    std::cout << "[0]: OPT" << std::endl;
    std::cout << "[1]: FIFO" << std::endl;
    std::cout << "[2]: LRU" << std::endl;
    std::cout << "[3]: CLOCK" << std::endl;
    std::cout << "put in not-num to exit" << std::endl;
}

void *producer(void *arg) {
    while (cur < 400) {
        sem_wait(&blank_num);
        pthread_mutex_lock(&mutex);
        if (cur < 400)
            cur++;
        pthread_mutex_unlock(&mutex);
        sem_post(&pro_num);
        usleep(1000);
    }
    return 0;
}

// consumer
void *consumer(void *num) {
    int *n = static_cast<int *>(num);
    while (cur < 400) {
        sem_wait(&pro_num);
        pthread_mutex_lock(&mutex);
        if (cur < 400 && (p.*func[*n])(cur))
            // if(cur<400 && (p.*f2)(cur))
            INT++;
        std::cout << order[cur].pagenum << " ";
        if ((cur + 1) % 40 == 0) {
            std::cout << std::endl;
        }
        pthread_mutex_unlock(&mutex);
        sem_post(&blank_num);
    }
    return 0;
}

// main manager
class Master {
  private:
    pthread_t pid, cid;
    int choose;

  public:
    Master(int choose) {
        this->choose = choose;
        func.push_back(f1);
        func.push_back(f2);
        func.push_back(f3);
        func.push_back(f4);
    }
    ~Master() {
        cur = -1;
        INT = 0;
        p.clear();
        sem_destroy(&blank_num);
        sem_destroy(&pro_num);
        pthread_mutex_destroy(&mutex);
    }
    void init() {
        std::cout << "In order storage there are 400 orders need to get page, "
                     "they are :"
                  << std::endl
                  << std::endl;
        sem_init(&blank_num, 0, NUM);
        sem_init(&pro_num, 0, 0);
        pthread_mutex_init(&mutex, NULL);
        pthread_create(&pid, NULL, producer, NULL);
        pthread_create(&cid, NULL, consumer, &choose);

        pthread_join(pid, NULL);
        pthread_join(cid, NULL);
    }
    void getResult() {
        std::cout << std::endl << std::endl;
        switch (choose) {
        case 0:
            std::cout << "OPT" << std::endl;
            break;
        case 1:
            std::cout << "FIFO" << std::endl;
            break;
        case 2:
            std::cout << "LRU" << std::endl;
            break;
        case 3:
            std::cout << "CLOCK" << std::endl;
            break;
        }
        std::cout << "----------------INT = " << INT
                  << " INT rate = " << INT * 1.0 / order.size() << "----------------------" << std::endl
                  << std::endl;
    }
};

int main() {
    srand((unsigned)time(NULL));

    for (int i = 0; i < NUM; i++) {
        Page p(rand() % NUM / 10);
        order.push_back(p);
    }
    p = PageManager(order);
    std::cout << std::endl
              << std::endl
              << "RAM size = " << p.get_RAM_Size() << std::endl
              << "you have -1 - 3 to choose" << std::endl
              << std::endl;
    showMessage();

    Master *m;
    while (std::cin >> choose) {
        if (choose < -1 || choose > 3) {
            std::cerr << "error choose" << std::endl;
            exit(0);
        } else if (choose == -1) {
            int newSize;
            std::cout << "new Size" << std::endl;
            std::cin >> newSize;
            p.set_RAM_SIZE(newSize);
            std::cout << "put in next choose -1 - 3" << std::endl;
            continue;
        }
        m = new Master(choose);
        m->init();
        m->getResult();
        delete m;

        showMessage();
    }
}
