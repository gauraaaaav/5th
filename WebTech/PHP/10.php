<!DOCTYPE html>
<html>
<body>

<form method="POST" action="">
    Name: <input type="text" name="name"><br><br>
    <input type="submit">
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    echo "Hello " . $_POST['name'];
}
?>

</body>
</html>