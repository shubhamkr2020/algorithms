<?php 
	if(isset($_FILES['naam'])) {
		$name = $_FILES['naam']['name'];	// name of file uploaded
		// $size = $_FILES['naam']['size'];
		// $type = $_FILES['naam']['type'];
		// $extension = strlower(substr($name,strpos($name, '.')+1));

		$tmp_name = $_FILES['naam']['tmp_name']; // temporary location

		if(file_exists($name)) {
			echo 'File already exists';
			die();
		}

		if(isset($name)) {
			if(!empty($name)) {
				echo 'OK file is ready to upload'.'<br>';

				$location = 'uploads/';		// name of the upload folder in same dir
				if(move_uploaded_file($tmp_name, $location.$name)) {
					echo 'succesfully uploaded';
				}
				else {
					echo 'There was an error !!';
				}

			}
			else {
				echo 'please upload a file';
			}
		}
	}
?>

<form action="fileupload.php" method="POST" enctype="multipart/form-data">
	<input type = "file" name="naam"><br><br>
	<input type="submit" value="Submit">
</form>