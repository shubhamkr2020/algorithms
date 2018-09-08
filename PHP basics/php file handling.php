<?php 
	/*
	1. To open a file use:
		$handle = fopen('filename.txt','r' or 'w' or 'a');

	2. To read from a file line by line use:
		i.) $var = file('filename.txt');
		// it will create a var array with everything from file line by line use foresch loop to access each element.
		ii.) $var = fread($handle, filesize('filename.txt'));
		// it will create a string of size 'filesize' or some size specified (ex-10) and will have everything from the file.

	3. To write to a file use:
		fwrite($handle, 'text');
		// use 'w' to write in a new file and 'a' to append in a file.
	
	4. When reading data from a file it is not always in line by line basis. So, we use explode:
		$var = fread($handle, filesize('filename.txt'));
		$data_array = explode(', ', $var);
		// it will divide the string $var into array of strings on the basis of ', '.

	5. Listing of Files in a directory:
		$dir = 'name_of_directory';
		if($handle = opendir($dir.'/')) {
			echo 'looking inside \''.$dir.'\'<br>';
			while($file = readdir($handle)) {
				if($file!='.' && $file!='..') {
					echo '<a href="'.$dir.'/'.$file.'">'.$file.'</a><br>';
				}
			}
		}
		// it will give you the clickable list of files in dir.......

	6. To find if a file with same name already exists in the dir use:
		if(file_exists($name_of_file)) {
			echo 'File already exists';
		}

	7. To delete a file use unlink() :
		if(@unlink('filename')) {
			echo 'file has been deleted';
		}

	8. To rename a file use rename() :
		if(rename('filename')) {
			echo 'file has been renamed';
		}

	*/
 ?>