<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
	<h1>Push_swap</h1>
  <p>Push_swap is a sorting algorithm implementation that sorts a stack of integers in ascending order. It uses two stacks and a set of instructions to manipulate the stacks and sort the integers.</p>

<h2>Usage</h2>

<p>To use the push_swap program, run it with a list of integers as arguments:</p>

<pre><code>./push_swap 4 67 3 87 23
</code></pre>

<p>The program will output a list of instructions that can be used to sort the integers:</p>

<pre><code>sa
pb
pb
sa
pa
pa
sa
</code></pre>

<p>The instructions can be piped into the checker program to verify that the output is correct:</p>

<pre><code>./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
</code></pre>

<p>The checker program will output "OK" if the instructions correctly sort the integers, or "KO" if they do not.</p>

<h2>Examples</h2>

<p>Here is an example of how to use the push_swap program:</p>

<pre><code>./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
</code></pre>

<p>This code will sort the list of integers `4 67 3 87 23` using the push_swap algorithm and then verify the result using the checker program.</p>
</body>
</html>
