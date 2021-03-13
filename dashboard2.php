<?php
    require_once "pdo.php";
    session_start();
    $_SESSION["dashboard"] = " ";
?>
<html>
<title>Final Year Project</title>
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
          .switch{
		  background-color:white;
            color: black;
			padding:0.03px;
            height : 80%;
            width:100%;
            opacity:0.75;
			font-family:Calibri;
            
		  
		  }
		  .switch2{
		  background-color:white;
            color: black;
			
            height : 80%;
            width:100%;
            
			font-family:Calibri;
            
		  }

       .button1 {
                background-color: #4CAF50; /* Green */
                border: none;
                color: white;
                width:140px;
				height:50px;
                text-align: center;
                text-decoration: none;
                display: inline-block;
                font-size: 16px;
                margin: 8px 4px;
                cursor: pointer;
                border-radius: 16px;
			   }
			
			.button2 {
                background-color: red;
                border: none;
                color: white;
                width:140px;
				height:50px;
                text-align: center;
                text-decoration: none;
                display: inline-block;
                font-size: 16px;
                margin: 4px 2px;
                cursor: pointer;
               border-radius: 16px;
			   }
			   .row {
                display: flex;
				height:80%;
                }

/* Create two equal columns that sits next to each other */
.column {
  flex: 50%;
   /* Should be removed. Only for demonstration */
}
			
	table {
  width: 100%;
  height:100%;
  font-size:30px;
}	
	.div5{
		background-color:#0CD1E9;
            color: white;
			padding:0.03px;
            height : 40px;
            width:100%;
            opacity:0.75;
			font-family:Calibri;
            	
	
	}
.bar{
background-color:black;
             color: white;
			padding:0.03px;
            height : 70px;
            width:100%;
            opacity:0.75;
			font-family:Calibri;
			
            display:flex;
}
.bar1{
background-color: #0CD1E9;
             color: white;
			padding:0.03px;
            height : 70px;
            width:100%;
            opacity:0.75;
			font-family:Calibri;
			
            display:flex;
}		
	
</style>
<body>
<div class="div1" ><h1>IOT based home appliance control (dashboard)</h1> </div>
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
<?php

if ( isset($_SESSION['success']) ) {
    echo '<p style="color:green">'.$_SESSION['success']."</p>\n";
    unset($_SESSION['success']);
}
echo('<div class="switch">');
echo('<div class="bar"><h1>Status</h1></div>');
echo('<table border="25">'."\n");

$stmt = $pdo->query("SELECT device_name, device_status,device_id FROM device");
while ( $row = $stmt->fetch(PDO::FETCH_ASSOC) ) {
    echo "<tr><td>";
    echo(htmlentities($row['device_id']));
    echo("</td><td>");
    echo(htmlentities($row['device_name']));
    echo("</td><td>");
    echo(htmlentities($row['device_status']));
    echo("</td></tr>\n");
}
echo('</table>');
echo('</div>');

?>
</div>
<div class="column">
<div class="bar1"><h1 align="center">Switch</h1></div>
<div class="switch2" >
<div>
<h1><b>Load1</b><button class="button1" onclick="window.location.href='ON1.php';" type="button">ON</button><button class="button2" onclick="window.location.href='OFF1.php';" type="button">OFF</button>
</h1>
</div>
<div>

<h1><b>Load2</b><button class="button1" onclick="window.location.href='ON2.php';" type="button">ON</button><button class="button2" onclick="window.location.href='OFF2.php';" type="button">OFF</button>
</h1>
</div>
<div>

<h1><b>Load3</b><button class="button1" onclick="window.location.href='ON3.php';" type="button">ON</button><button class="button2" onclick="window.location.href='OFF3.php';" type="button">OFF</button>
</h1>
</div>
<div>

<h1><b>Load4</b><button class="button1" onclick="window.location.href='ON4.php';" type="button">ON</button><button class="button2" onclick="window.location.href='OFF4.php';" type="button">OFF</button>
</h1>
</div>
<div>

<h1><b>Load5</b><button class="button1" onclick="window.location.href='ON5.php';" type="button">ON</button><button class="button2" onclick="window.location.href='OFF5.php';" type="button">OFF</button>
</h1>
</div>

</div>
</div>
</div>
<div class="div5">
 <p align="center">&copy 2021| Group 9</p>
</div>
</body>

</html>