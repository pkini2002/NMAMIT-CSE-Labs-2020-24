//index.html

<!DOCTYPE html>
<html>
   <title>Sample Example </title>
<body>
<h1> <center> Example of JSP </center> </h1>
<hr>
<form method="post" action="add.jsp">
<label for="firstname">First Name: </label> <br/>
<input type="text" id="firstname" name="firstname"/> <br/>
<label for="lastname">Last Name: </label>
<input type="text" id="lastname" name="lastname"/> <br/>
<input type="submit" value="submit">
</form>
</body>
</html>

// add.jsp

<%@ page language="java" contentType="text/html; charset=UTF-8"
pageEncoding="UTF-8"%>
<html>
<head>
<title>Using GET Method to Read Form Data</title>
</head>
<body>
<h1>Using GET Method to Read Form Data</h1>
<ul>
<li><p><b>First Name:</b>
<%= request.getParameter("firstname")%>
</p></li>
<li><p><b>Last Name:</b>
<%= request.getParameter("lastname")%>
</p></li>
</ul>
</body>
</html>

