<?php 
  /*
  1. Does it exists or "Has it been submitted ?"
  2. Is it empty or "Does value = NULL"
  3. Display back to user
  4. if there is no sensitive data we can use GET instead of POST
  5. for storing a session use session_start() at the begin and $_SESSION['name'] = ..... to set names of session and access session name.
  6. Use different pages to set and unset a session.
  7. Dont forget to set a session before unset ...
  8. to unset 
      session_start();
      unset($_SESSION['name_of_session'])
      // session with name name_of_session will be closed.
      session_destroy(); // destroy all sessions.
  9. cookies are also used to store session data for certaion interval of time.
        setcookie('name','value',time()+interval);
  */

  session_start();
  
  if(isset($_POST['username']) && isset($_POST['password'])) {
    // for security htmlentities should be used to make the input html entity and not html tags......
    $username = htmlentities($_POST['username']);
    $password = htmlentities($_POST['password']);
    if(!empty($username) && !empty($password)) {
      echo 'Welcome '.$username;
      $_SESSION['username'] = $username;
    }
    else {
      echo 'Fill in all fields !!!.';
    }
  }

 ?>

<!-- form created will be posted to the action page(here index.php)....
// and the input is processed in php snippet -->
 <form action="index.php" method="POST">
   Username<br><input type="text" name="username"><br>
   Password<br><input type="password" name="password"><br>
   <input type="submit" value="Submit">
 </form>