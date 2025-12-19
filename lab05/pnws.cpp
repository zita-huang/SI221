/*
  The function pnws(in) reads in whitespace characters from the input
  stream until it comes across the next non-whitespace character.  This
  character is not read in, it is the next character waiting to be read
  in.  However, pnws returns the value of that next character waiting
  to be read in.  Suppose you're waiting to read input, and either a
  positive integer is coming, or a name.  You don't know which.  But
  if it's a number an int i should be set to the number if it's a
  name a string s should be set to the name.  psws can help!

  int i;
  string s;
  char c = pnws(cin);
  if ('0' <= c && c <= '9')
    cin >> i;
  else
    cin >> s;

  Pretty handy little function, eh?
 */
char pnws(istream &in) { 
  char c;
  for(c = in.peek(); c == ' ' || c == '\t' || c == '\n'; c = in.peek())
    in.get();
  return c;
}
