<?php

echo "hello";
// Create connection
$con=mysqli_connect("epiknice.ckj7yn9ymbsk.us-east-1.rds.amazonaws.com","epiknice","engineer","epiknice");

// Check connection
if (mysqli_connect_errno()) {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
}

$username = mysqli_real_escape_string($con, $_POST['username']);
$password = mysqli_real_escape_string($con, $_POST['pass1']);

if($username == ""){
echo "You Suck";
mysqli_close($con);
header('Location:downloads.html');
}

$result = mysqli_query($con, "SELECT * FROM Users WHERE Users = '$username'");


$sql="INSERT INTO users (Users, Password, Email, Phone_Number)
VALUES ('$username', '$password', '$email', '$phonenumber')";

if (!mysqli_query($con,$sql)) {
  die('Error: ' . mysqli_error($con));
}
echo "1 record added";

mysqli_close($con);

header('Location:downloads.html');
?> 


