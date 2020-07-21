<?php
$servername = "localhost”;
$username = 'root';
$password = '123456';
$dbname = 'labexamdb';

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$id = $_GET["id"];

$sql = "SELECT * FROM tb WHERE id = $id";

if ($conn->query($sql) == TRUE) 
{
		echo "Record selected successfully";
}
else
{
    	echo "Error: " . $sql . "<br>" . $conn->error;
}
/*
if(mysql_num_rows($sql)>0)
{
	$result=mysql_fetch_array($sql);
	

}*/

$conn->close();
?>