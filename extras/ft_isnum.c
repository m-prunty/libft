#include "libft.h"
/**
 * @brief function to check if a string value is an integer
 *
 * @param str string to check
 * @return 1 if isnum else 0
 */
int ft_isnumi(char *str)
{
	if (*str == '\0' && *(str-1))
		return (1);
	if (ft_isdigit(*str))
		return (ft_isnumi(++str) * 1);
	return (0);
}
/**
 * @brief function to check if a string value is a float
 *
 * @param str string to check
 * @param dec set to 1 to prime boolean switch to deal with a single decimal
 * @return 1 if isnum else 0
 */
int ft_isnumf(char *str, int dec)
{
	if (*str == '\0' && *(str-1) && *(str-1) != '.')
		return (1);
	if (dec && *str == '.' && *(str-1))
		return (ft_isnumf(++str, 0) * 1);
	if (ft_isdigit(*str))
		return (ft_isnumf(++str, dec) * 1);
	return (0);
}
/**
 * @brief main function to test the isnumi and isnumf functions
 *
 * @return int
int main()
{
	char *str1 = "123.456";
	char *str2 = "123";
	ft_printf("isnumi: %i\n", ft_isnumi(str2));
	ft_printf("isnumf: %i\n", ft_isnumf(str1, 1));
	ft_printf("isnumi: %i\n", ft_isnumi(""));
	ft_printf("isnumf: %i\n", ft_isnumf("0.0", 1));
	ft_printf("isnumf: %i\n", ft_isnumf(".0", 1));
	ft_printf("isnumf: %i\n", ft_isnumf("0.", 1));
	return (0);
}
 */
