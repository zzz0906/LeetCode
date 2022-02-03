#include<bits/stdc++.h>
using namespace std;
double findKth(int a[], int m, int b[], int n, int k)  
{  
    //always assume that m is equal or smaller than n
	//THIS BOUNDART CONDITION IS VERY IMPORTANT:  
    if (m > n)  
        return findKth(b, n, a, m, k);  
    if (m == 0)  
        return b[k - 1];  
    if (k == 1)  
        return min(a[0], b[0]);  
    //divide k into two parts  
    int pa = min(k / 2, m), pb = k - pa;  
    if (a[pa - 1] < b[pb - 1])  
        return findKth(a + pa, m - pa, b, n, k - pa);  
    else if (a[pa - 1] > b[pb - 1])  
        return findKth(a, m, b + pb, n - pb, k - pb);  
    else  
        return a[pa - 1];  
}  
  
class Solution  
{  
public:  
    static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)  
    {
		int m = nums1.size();int n = nums2.size();
		if (m == 0) if (n & 0x1) return nums2[n/2];else return ((double)nums2[n/2]+(double)nums2[n/2-1])/2; 
		if (n == 0) if (m & 0x1) return nums1[m/2];else return ((double)nums1[m/2]+(double)nums1[m/2-1])/2;
		int A[m];
		int B[n];
		for (int j = 0;j<m;j++ ) A[j] = nums1[j];
		for (int j = 0;j<n;j++)  B[j] = nums2[j];  
        int total = m + n;  
        if (total & 0x1)  
            return findKth(A, m, B, n, total / 2 + 1);  
        else  
            return (findKth(A, m, B, n, total / 2)  
                    + findKth(A, m, B, n, total / 2 + 1)) / 2;  
    }  
};
