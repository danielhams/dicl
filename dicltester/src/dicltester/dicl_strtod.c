#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

void dicl_strtodtest()
{
  printf("Beginning strtod test\n");

  double testvald = 20.0;
  printf("Test strtod is %lf\n", testvald);

  const char *tststrtod = "0x0fad";
  char *endptr;
  double strtodresult = strtod(tststrtod,&endptr);
  printf("Parsed strtod is %lf\n", strtodresult);

  long double testvalld = 20.0;
  printf("Test strtold is %Lf\n", testvalld);

  long double strtoldresult = strtold(tststrtod,&endptr);
  printf("Parsed strtold is %Lf\n", strtoldresult);

  return;
}
