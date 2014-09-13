#include "post.h"
#include "common.h"

/*
 * Replaces a by b in orig. strlen(a) should be >= strlen(b) or
 * it won't work correctly.
 */
static int replace(char *orig, char *a, char *b);

/*
 * This table lists moves which can be canceled, to make a given
 * correct sequence of moves shorter and equivalent. Also, we normalize
 * some moves (like "lr" -> "rl") in order to find more cancelations.
 */
static char *table[] = {
	"ff","FF", "uu","UU", "bb","BB",
	"dd","DD", "rr","RR", "ll","LL",

	"Ll","", "lL","", "Rr","",
	"rR","", "Dd","", "dD","",
	"Ff","", "fF","", "Uu","",
	"uU","", "Bb","", "bB","",

	"UUU","u", "uuu","U", "FFF","f",
	"fff","F", "rrr","R", "RRR","r",
	"DDD","d", "ddd","D", "bbb","B",
	"BBB","b", "LLL","l", "lll","L",

	"bf","fb", "bF","Fb", "Bf","fB",
	"BF","FB",

	"lr","rl", "Lr","rL", "lR","Rl",
	"LR","RL",

	"du","ud", "dU","Ud", "Du","uD",
	"DU","UD",
};

void simplify(char *str)
{
	unsigned int i;
	int R = 1;
	
	while (R != 0) {
		R = 0;

		for (i = 0; i < sizeof(table) / sizeof(char*); i += 2)
			R += replace(str, table[i], table[i+1]);
	}
}

static int replace(char *orig, char *a, char *b)
{
	char *dest = orig;
	int j, k;
	int R = 0;

	while (*orig) {
		j = 0;

		/* Find common prefix of a and orig */
		while (orig[j] && a[j] && orig[j] == a[j])
			j++;

		/* A is a prefix of orig */
		if (a[j] == 0) {
			R = 1; /* We did work */

			for (k = 0; b[k]; k++)
				dest[k] = b[k];

			dest += k;
			orig += j;
		} else {
			*dest++ = *orig++;
		}
	}

	*dest = 0;
	return R;
} 
