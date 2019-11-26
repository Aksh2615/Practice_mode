<?php
  require('inc/config.php');
?>
<!DOCTYPE html>
<html>
<head>
	<title>Send Messages</title>
	<link rel="stylesheet" type="text/css" href="css/advertise.css">
  <link rel="stylesheet" type="text/css" href="css/footer.css">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
</head>
<style type="text/css">
  .color-white{
    color: white;
  }
</style>
<style type="text/css">
  footer{
    position: absolute;
    bottom: 0;
    width: 100%;
  }
</style>
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
        <li><a href="message.php" >MESSAGES</a></li>
        <li><a href="about_us.php">ABOUT US</a></li>
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


<div class="container">
  <h2 style="text-align:center; color:white;">Delete Products</h2>
  <form class="form-horizontal" action="del.php" method="POST">
    <div class="form-group">
      <label class="control-label col-sm-2" style="color:white;">Advt Id:</label>
      <div class="col-sm-10">
        <input type="text" class="form-control" name="advt" placeholder="Advt id of the product to be deteled"><div>
          </div>
      </div>
    </div>
    <div class="form-group">        
      <div class="col-sm-offset-2 col-sm-9"><input type="submit" id="su" name="sub" class="btn btn-primary">
      </div>
    </div>
</form>
</div>

    <?php
              if(isset($_POST['sub'])){
                
                $id = $_POST['advt'];
                $query1 = "DELETE FROM advertisement WHERE advertisement.advt_id = '$id'";
                $result1 = mysqli_query($db,$query1);
                if($result1){
                     echo "<script type='text/javascript'>alert('Deleted Successfully!')</script>";
                }
                else{
                     echo "<script type='text/javascript'>alert('Error!!! Enter valid id')</script>";
                }
              }
            ?>
<footer class="container-fluid bg-4 text-center">
  <p>@ 2019 Copyright: <a href="home.php">www.CampConnect.com </a>| Designed by Anand Kumar Singh & Ashita Aggarwal</p> 
</footer>