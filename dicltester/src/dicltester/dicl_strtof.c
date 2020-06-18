#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

void dicl_strtoftest()
{
  printf("Beginning strtof test\n");

  float testvald = 20.0f;
  printf("Test strtof is %f\n", testvald);

  const char *tststrtof = "0x0fad";
  char *endptr;
  float strtofresult = strtof(tststrtof,&endptr);
  printf("Parsed strtof is %f\n", strtofresult);

  const char *newstrtof = "-0x1p-1074";
  float expected = -5e-324f;
  float newresult = strtof(newstrtof,&endptr);
  printf("Parsed newstrtof is %f\n", newresult);
  printf("This should be %f\n", expected);
  if( expected == newresult ) {
    printf("They match - great!\n");
  }
  else {
    printf("They don't match - PROBLEM!\n");
  }

  return;
}
