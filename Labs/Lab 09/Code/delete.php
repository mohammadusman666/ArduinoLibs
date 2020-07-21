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

$sql = "DELETE FROM tb WHERE firstName = $firstName";

if ($conn->query($sql) == TRUE)
{
	echo "Record deleted successfully";
}
else
{
	echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
?>
