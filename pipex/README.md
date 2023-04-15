<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
	<h1>Pipex</h1>
  <p>Pipex is a program that simulates the behavior of the shell command pipeline. It reads input from a file, performs a series of transformations on that input, and then outputs the result to another file.</p>

<h2>Usage</h2>

<p>The pipex program is called with four arguments:</p>

<pre><code>./pipex infile cmd1 cmd2 outfile
</code></pre>

<p>The program will read input from `infile`, pass it through `cmd1`, then through `cmd2`, and finally write the output to `outfile`. The program simulates the behavior of the shell command:</p>

<pre><code> &lt; infile cmd1 | cmd2 &gt; outfile
</code></pre>

<h2>Examples</h2>

<p>Here is an example of how to use the pipex program:</p>

<pre><code>./pipex infile "grep foo" "wc -l" outfile
</code></pre>

<p>This code will read input from the file `infile`, pass it through the `grep` command to find all occurrences of the string "foo", then pass the output through the `wc` command to count the number of lines in the output. The final result will be written to `outfile`.</p>

</body>
</html>
