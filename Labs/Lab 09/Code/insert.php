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

$firstName = $_GET["firstName"];
$lastName = $_GET["lastName"];
$age = $_GET["age"];

$sql = "INSERT INTO tb (firstName, lastName, age)
	VALUES ('$firstName', '$lastName', '$age')";

if ($conn->query($sql) === TRUE) 
{
	echo "New record created successfully";
}
else
{
	echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
?>
