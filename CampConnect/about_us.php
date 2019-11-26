<?php
require('inc/config.php');
?>
<!DOCTYPE html>
<html style="margin: 0;padding: 0;">
<head>
	<title>About Us</title>
	<link rel="stylesheet" type="text/css" href="css/advertise.css">
    <link rel="stylesheet" type="text/css" href="css/footerf.css">
    <link rel="stylesheet" type="text/css" href="css/purchase1.css">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>

  <link href="//maxcdn.bootstrapcdn.com/font-awesome/4.1.0/css/font-awesome.min.css" rel="stylesheet">
<link href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css" rel="stylesheet" integrity="sha256-MfvZlkHCEqatNoGiOXveE8FIwMzZg4W85qfrfIFBfYc= sha512-dTfge/zgoMYpP7QbHy4gWMEGsbsdZeCXz7irItjcC3sPUFtf0kuFbDz/ixG7ArTxmDjLXDmezHubeNikyKGVyQ==" crossorigin="anonymous">

</head>
<body style="background-color: #212F3C;margin: 0;padding: 0;">
 
	<nav class="navbar navbar-inverse">
  <div class="container">
    <div class="navbar-header">
      <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#myNavbar">
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>                        
      </button>
        <a class="navbar-brand" href="home.php"><strong><i>CAMPCONNECT</i></strong></a>
    </div>
    <div class="collapse navbar-collapse" id="myNavbar">
      <ul class="nav navbar-nav navbar-right">
        <li><a href="home.php">HOME</a></li>
        <li><a href="my_products.php">MY PRODUCTS</a></li>
        <li><a href="bought_products.php">BOUGHT PRODUCTS</a></li>
        <li><a href="message.php">MESSAGES</a></li>
        <li class="active"><a href="about_us.php">ABOUT US</a></li>
        <li class="dropdown"><a href="#" class="dropdown-toggle" data-toggle="dropdown"><?php echo $_SESSION['email']; ?><span class="caret"></span></a>
        <ul class="dropdown-menu">
          <li><a href="change_password.php">Change Password</a></li>
          <li><a href="logout.php">Logout</a></li>
        </ul>
        </li>
      </ul>
    </div>
  </div>
</nav>

  <h1 style="text-align: center; padding: 20px 0px 20px 10px; color:white;">About Us</h1>
  <!--<div class="container">-->
  	<div style="background-color: #212F3C;  width: 100%;">
  		<p style="color: white;padding: 30px 30px 30px 30px;font-size: 25px;text-align: center;">CampConnect.com is a free local classifieds site secially designed for College Campuses. Sell anything like mobiles, laptops and Books(Notes). Submit ads for free . If you want to buy something - here you will find interesting items, cheaper than in the store. Start buying and selling in the most easy way on CampConnect.com.</p>
  		<center><h2 style="padding: 10px 10px 30px 10px;color: white;">Connect Us</h2></center>
  	            <div style="padding-bottom: 30px;">
  	            <center><a href="https://www.facebook.com/aksh.singh.5030"><i id="social-fb" class="fa fa-facebook-square fa-3x social"></i></a>
	            <a href="https://plus.google.com/u/0/"><i id="social-gp" class="fa fa-google-plus-square fa-3x social"></i></a>
	            <a href="https://mail.google.com/mail/u/0"><i id="social-em" class="fa fa-envelope-square fa-3x social"></i></a>
	            </center>
	            </div>
  	</div>
  <!--</div>-->

<footer class="container-fluid bg-4 text-center">
  <p>@ 2019 Copyright: <a href="home.php">www.CampConnect.com </a>| Designed by Anand Kumar Singh & Ashita Aggarwal</p> 
</footer>