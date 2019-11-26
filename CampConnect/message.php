<?php
  require('inc/config.php');
?>
<!DOCTYPE html>
<html>
<head>
	<title>My Products</title>
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
  <script src="//code.jquery.com/jquery-1.11.1.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>	
  <link rel="stylesheet" type="text/css" href="css/advertise.css">
	<link rel="stylesheet" type="text/css" href="css/purchase1.css">
    <link rel="stylesheet" type="text/css" href="css/footerf.css">
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
        <li class="active"><a href="message.php">MESSAGES</a></li>
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

<?php
    $email_id = $_SESSION['email'];
    $query = "SELECT * FROM Messages WHERE receiver_id ='$email_id'";
    $result = mysqli_query($db,$query);

    while ($row = mysqli_fetch_assoc($result)){
          $sender_id = $row["sender_id"];
          $query2 = "SELECT *FROM Users WHERE Nitc_email_id = '$sender_id'";
          $result2 = mysqli_query($db,$query2);
          $row2 = mysqli_fetch_assoc($result2);
          $sender_name = $row2["User_name"];  
          ?> 
         <div class="container">
<div class="row row-margin-bottom">
            <div class="col-md-12 no-padding lib-item" data-category="view">
                <div class="lib-panel">
                    <div class="row box-shadow">
                        
                        <div class="col-md-12">
                            <div class="lib-row lib-message">
                                <b><?php echo $sender_id; ?></b>
                                <!--<div class="lib-header-seperator"></div>-->
                            </div> 

                            <div class="lib-row lib-data">
                                 <?php echo $row["message"]; ?>
                            </div>
                            <div class="lib-row lib-desc" style="text-align: right;">
                                 <?php echo $row["msg_date"] ?>
                                
                            </div>
                            
                            
                        </div>
                    </div>
                </div>
            </div>
            <!--<div class="col-md-1"></div>-->
        </div>
      </div>    
    <?php
    } 

?>

<a href="send_message.php"><center><button style="width: 50%;" type="submit" id="sold" name="sold" class="btn btn-primary" >CLICK TO MESSAGE</button></center></a>  


<footer class="container-fluid bg-4 text-center">
  <p>@ 2019 Copyright: <a href="home.php">www.CampConnect.com </a>| Designed by Anand Kumar Singh & Ashita Aggarwal</p> 
</footer>