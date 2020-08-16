#include <stdio.h>

int
get_nth(int *l1, int m, int *l2, int n, int i)
{
	int p, e;

	p = 0;
	while (p <= i) {
		while ((!n && i >= p) || (n && m &&*l1 <= *l2 && i >= p && m)) {
			e = *l1;
			++l1;
			++p;
			--m;
		}
		while ((!m && i >= p) || (n && m && *l1 > *l2 && i >= p)) {
printf("%d\n", (!m && i >= p));
printf("ee\n");
			e = *l2;
			++l2;
			++p;
			--n;
		}
	}	
	return e;
}

double
findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	int len;

	len = nums1Size + nums2Size;
	if (len%2) {
		--len;
		len /= 2;
		return get_nth(nums1, nums1Size, nums2, nums2Size, len);
	}
	len /= 2;
	return ((double)get_nth(nums1, nums1Size, nums2, nums2Size, len - 1) +
	        (double)get_nth(nums1, nums1Size, nums2, nums2Size, len)) / 2;
	
}

int
main()
{
	
	int l1[] = {};
	int l2[] = {2, 3};
	printf("%f\n", findMedianSortedArrays(&l1[0], 0, &l2[0], 2));
}
