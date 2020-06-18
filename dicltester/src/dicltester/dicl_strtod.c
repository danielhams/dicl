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

  const char *newstrtod = "-0x1p-1074";
  double expected = -5e-324;
  double newresult = strtod(newstrtod,&endptr);
  printf("Parsed newstrtod '%s' is %f\n", newstrtod, newresult);
  printf("This should be %f\n", expected);
  if( expected == newresult ) {
    printf("They match - great!\n");
  }
  else {
    printf("They don't match - PROBLEM!\n");
  }

  return;
}
