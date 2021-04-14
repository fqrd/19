#include <string.h>
#include <stdio.h>
#include "../libft.h"

int test_ft_strdup()
{
	printf("------------\n----STRDUP----\n------------\n");

	char *m = "The long-string instrument is a musical instrument in which the string is of such a length that the fundamental transverse wave is below what a person can hear as a tone (±20 Hz). If the tension and the length result in sounds with such a frequency, the tone becomes a beating frequency that ranges from a short reverb (approx 5–10 meters) to longer echo sounds (longer than 10 meters). Besides the beating frequency, the string also gives higher pitched natural overtones. Since the length is that long, this has an effect on the attack tone. The attack tone shoots through the string in a longitudinal wave and generates the typical science-fiction laser-gun sound as heard in Star Wars.[1] The sound is also similar to that occurring in upper electricity cables for trains (which are ready made long-string instruments in a way).";
	if(strcmp(ft_strdup(m),strdup(m) != 0))
	{
		printf("ERROR\n");
	}
	else
	{
		printf("OK\n");
	}

	return (0);
}