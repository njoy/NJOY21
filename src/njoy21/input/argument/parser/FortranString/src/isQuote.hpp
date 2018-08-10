bool isQuote( char c ){
  if ( ( c == '\'' ) or ( c == '*' ) or ( c == '"' ) ){
    quote = c;
    return true;
  }
  return false;
}

