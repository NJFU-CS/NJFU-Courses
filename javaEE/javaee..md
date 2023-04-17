```xml
<servlet>
    <servlet-name>hello</servlet-name>
    <servlet-class>com.nanlin.servlet.Testservlet</servlet-class>
    <!-- <load-on-startup>1</load-on-startup> -->
<servlet>
<servlet-mapping>
    <servlet-name>hello</servlet-name>
    <url-pattern>/hello</url-pattern>
</servlet-mapping>
```


```java
public class WelcomeServlet extends HttpServlet(
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException IOException{
        response.setContentType("text/html;charset=utf-8");
        PrintWriter out = response.getWriter();
        out.println(“欢迎来到本系统!“);
    }
```
- 在WebRoot文件夹web.ML配置文件中关于servlet 配置如下
```xml
<servlet>
<servlet-name>WelcomeSerylet</servlet-name>
<servlet-class>servlets.WelcomeServlet</servlet-class>
</servlet>
<servlet-mapping>
<servlet-name>WelcomeServlet</servlet-name>
<url-pattern>/hello</url-pattern>
</servlet-mapping>
```