<!DOCTYPE html>
<html>
<head>
</head>
<body>
	<h1>so_long</h1>
	<p>so_long is a simple 2D game developed as part of the 42 school curriculum. The game is built using the miniLibX graphics library and requires X11 to run.</p>
	<h2>Installation</h2>
	<ol>
		<li>Clone the repository: <code>git clone https://github.com/JEGHTNER/42Seoul_2Circle.git</code></li>
		<li>Navigate to the cloned directory: <code>cd so_long</code></li>
		<li>Compile the game: <code>make</code></li>
		<li>Run the game: <code>./so_long <i>mapfile</i></code></li>
	</ol>
	<p>The game can be played using the arrow keys to move the player character. The goal is to collect all the collectibles and reach the exit without colliding with any enemies.</p>
	<h2>Map format</h2>
	<p>The game map is defined in a text file with the <code>.ber</code> extension. The map is made up of the following elements:</p>
	<ul>
		<li>0 - empty space</li>
		<li>1 - wall</li>
		<li>C - collectible</li>
		<li>E - exit</li>
		<li>P - player character</li>
		<li>X - enemy</li>
	</ul>
	<p>Example map:</p>
	<pre>
111111
1CE0E1
100001
1E0001
1111P1
</pre>
</body>
</html>
