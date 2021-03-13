<?php
session_start();
if ( ! isset($_SESSION['dashboard']) ) {
    
    die('unautherized access!');
}
?>
<?php
$servername = "localhost";
$username = "iot";
$password = "iot";
$dbname = "iotdb2";

try {
  $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
  // set the PDO error mode to exception
  $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

  $sql = "UPDATE device SET device_status='ON' WHERE device_id=5";

  // Prepare statement
  $stmt = $conn->prepare($sql);

  // execute the query
  $stmt->execute();

  // echo a message to say the UPDATE succeeded
  echo $stmt->rowCount() . " records UPDATED successfully";
} catch(PDOException $e) {
  echo $sql . "<br>" . $e->getMessage();
}
$_SESSION['success']="Switching Successful";
$conn = null;
?>
<?php
    session_start();
    unset($_SESSION['dashboard']);
    header("Location: dashboard.php");