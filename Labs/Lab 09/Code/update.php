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
$firstName = $_GET["firstName"];

$sql = "UPDATE tb SET firstName = '$firstName' WHERE id = $id";

if ($conn->query($sql) == TRUE) 
{
	echo "Record updated successfully";
}
else
{
	echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
?>
