<?php

 require('inc/config.php');
?>
<!DOCTYPE html>
<html>
<head>
	<title>CampConnect</title>
	<link rel="stylesheet" type="text/css" href="css/home.css">
	<link rel="stylesheet" type="text/css" href="css/advertise.css">
    <link rel="stylesheet" type="text/css" href="css/footer.css">
    
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
   
</head>
<style type="text/css">
.tp1{
	color: white;
	font-size: 80px;
	margin-top: 200px;
}

</style>
<body>
    <header>
    
<nav class="navbar navbar-inverse">
    <a class="navbar-brand" href="home.php"><strong><i>CAMPCONNECT</i></strong></a>
    <div class="collapse navbar-collapse" id="myNavbar">
      <ul class="nav navbar-nav navbar-right">
          
        <li class="active"><a href="home.php">HOME</a></li>
        <li><a href="my_products.php">MY PRODUCTS</a></li>
        <li><a href="bought_products.php">BOUGHT PRODUCTS</a></li>
        <li><a href="message.php">MESSAGES</a></li>
        <li><a href="about_us.php">ABOUT US</a></li>
        <li class="dropdown"><a href="#" class="dropdown-toggle" data-toggle="dropdown"><?php echo $_SESSION['email']; ?><span class="caret"></span></a>
        <ul class="dropdown-menu">
          <li><a href="change_password.php">Change Password</a></li>
          <li><a href="logout.php">Logout</a></li>
        </ul>
        </li>
      </ul>
    </div>
    </nav>
</div>
</div>
<center>
    <div class="text-center">
        <h1 class="tp1">Do U Want To?</h1>

        <div class="button">
        	<a href="laptop.php" class="btn-one button_n">Advertise</a>
        	<a href="purchase.php" class="btn-two button_n">Purchase</a>
        </div>
    </div>
</center>
</header>

<footer class="container-fluid bg-4 text-center">
  <p>@ 2019 Copyright: <a href="home.php">www.CampConnect.com </a>| Designed by Anand Kumar Singh & Ashita Aggarwal</p> 
</footer>


