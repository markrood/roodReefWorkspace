This is the matrix sign project.

You have to first play the song for that year playlist and let it store the following in firebase:
   WappSongs
    99999999999  //a key number
        year    2024
        Name    Jeff

Once this key and data is stored in the database, play a wapp 
playlist for a particular year and the system will
make a rest call to volumio and get song Title and Artist
and generate the key for that song title.  
The system will use this key to get the year of playlist
and the name of the person that put the song on for that year.
It will concatinate Title:Artist:Who put it on:Year and 
display it on the sign.