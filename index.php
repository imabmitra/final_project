<?php
    
    
	
	session_start();
    if ( isset($_POST["uname"]) && isset($_POST["psw"]) ) {
        unset($_SESSION["uname"]);  // Logout current user
        
	   if ( ($_POST['psw'] == 'Tensports@123') && ($_POST['uname'] == 'groupnine') ) {
            $_SESSION["email"] = $_POST["uname"];
            $_SESSION["signin"] = "Logged in.";
            header( 'Location: dashboard.php' ) ;
            return;
        } 
		
		else {
            $_SESSION["error"] = "Incorrect password.";
            header( 'Location: index.php' ) ;
            return;
        }
    }
?>
<html>
<title>Group 9 Project</title>


<style>
/*header time style*/
	   .time{background-color:#E0E8E9;
            color: black;
            padding:0.05px;
			
            width:100%;
            opacity:0.75;
			font-family:verdana;
            font-size:10px;
			}

/*header style*/
	   .div1{background-color:#0CD1E9;
            color: white;
			padding:0.03px;
            height : 70px;
            width:100%;
            opacity:0.75;
			font-family:Calibri;
            display:flex;
			}			



/*div 4 style*/
	   .div4{background-color:white;
            max-width: 500px;
            margin: auto;
			color: black;
            height :73%;
            width:100%;
            opacity:0.75;
			font-family:Calibri;
			align-items: center;
			padding: 10px;
            }		
/*div5 style*/
	   .div5{background-color:#0CD1E9;
            color: white;
			padding:0.03px;
            height : 40px;
            width:100%;
            opacity:0.75;
			font-family:Calibri;
            }			

       .button1 {
                 background-color: #4CAF50; /* Green */
                border: none;
                color: white;
                padding: 14px 20px;
                text-align: center;
                text-decoration: none;
                display: inline-block;
                font-size: 16px;
                margin: 16px 4px;
                cursor: pointer;
                border-radius: 8px;
			   }
			
			
			.container {
                 padding: 16px;
                display: flex;}
			input {
				  width: 100%;
				  padding: 12px 20px;
				  margin: 8px 0;
				  display: inline-block;
				  border: 1px solid #ccc;
				  border-radius: 4px;
				  box-sizing: border-box;
				}
				.row {
                display: flex;
				height:80%;
                }

/* Create two equal columns that sits next to each other */
.column {
  flex: 30%;
  background-color: #e6ffff;
   /* Should be removed. Only for demonstration */
}
.column2 {
  flex: 70%;
   /* Should be removed. Only for demonstration */
}
.bar1{
background-color: #4d004d;
             color: white;
			
            height : 50px;
            width:100%;
            opacity:0.75;
			font-family:Calibri;
			
			font-size: 32px;
           
}
.content{
	       color: white;
			font-family:Calibri;
			font-size: 32px;
			text-align: right;
}
.row2 {
                display: flex;
				height:20%;
                }

/* Create two equal columns that sits next to each other */
.column3 {
  flex: 5%;
  
}
.column4 {
  flex: 95%;
   
}	
</style>
<body>
<div class="div1"><div style="width:80%"><h1>IOT based home appliance control </h1></div>
</div>
<div class="time">
     <p id="date" align="right"></p>
                       <!--script of date and time-->
					   <script>
                                var d = Date();
                                document.getElementById("date").innerHTML = d;
                        </script>
</div>

<div class="row">

<div class="column">
<div class="bar1"><p align="center">Sign In Container</p></div>
<?php
if ( isset($_SESSION['error']) ) {
    echo '<p style="color:red">'.$_SESSION['error']."</p>\n";
    unset($_SESSION['error']);
}
?>
<form method="post">
      <label for="uname"><b>Username</b></label>
      <input type="text" placeholder="Enter Username" name="uname" required>

      <label for="psw"><b>Password</b></label>
      <input type="password" placeholder="Enter Password" name="psw" required>
        
      <button class="button1" type="submit">Login</button>
</form>	  
      
</div>
<div class="column2" style="background-image: url('https://base.imgix.net/files/base/ebm/machinedesign/image/2019/04/machinedesign_12506_iot_growth_533577794.png?auto=format&fit=max&w=1200');">
<div class="row2"><div class="column3"><img src="AITH.jpg" width="120" height="120"></div><div class="column4"><h1 class="content">Dr. Ambedkar Institute of Technology for Handicapped, Kanpur, U.P.</h1></div></div>

<p align="center" style="color:#4d004d; font-family:Calibri; font-size:40px"><strong>B.Tech. Final Year Project</strong></p>
<div><p align="center" style="color:black; font-family:Calibri; font-size:30px"><strong>Department of Electronics Engineering</strong></p>
</div><div><p align="center" style="color:white; font-family:Calibri; font-size:20px"><strong>REC754</strong></p></div>
<div style="background-color:#d9d9d9; font-family:Calibri; color:#4d004d; opacity:0.65; line-height: 1"><h1>Group No.9</h1>
<div style="color:black; line-height: 1;"><h3>Project Guide</h3>Mr. Ravi Kumar Kannaujia
<h3>Group Members</h3>
Abhishek Kumar(1716630003)<br> 
Pawan Prajapati(1716630040)<br>
Nainesh Kumar(1616630028)<br>
Rahul Kumar(1716630046)
</div>
</div>

</div>
</div>




<div class="div5">
 <p align="center">&copy 2021| Group9</p>
</div>

</body>
</html>