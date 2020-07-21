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

$status = $_POST["status"];
$date = date("Y-m-d");
$time = date("h:i:s");

$sql = "INSERT INTO tb (status, dt, tm)
	VALUES ('$status', '$date', '$time')";

if ($conn->query($sql) === TRUE) 
{
	echo "OK";
}
else
{
	echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
?>
