<%@ page language="java" import="java.util.*" pageEncoding="utf8"%>
<%
    HttpSession sess = request.getSession();
    try {
    	int isLogin = (int)sess.getAttribute("login");
    } catch (java.lang.NullPointerException e){
    	response.sendRedirect("login.jsp");
    	return ;
    }
%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'del.jsp' starting page</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

  </head>
  
  <body>
    <form action="servlet/APKManagerServlet" method="post">
    	id: <input type="text" name="id"/>
    	<input type="hidden" name="action" value="del" />
    	<input type="submit" value="submit" />
    </form>
  </body>
</html>
