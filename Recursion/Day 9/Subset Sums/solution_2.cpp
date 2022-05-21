void subsetSums(int arr[], int l, int r, int sum = 0)
{
    // Print current subset
    if (l > r) {
        cout << sum << " ";
        return;
    }
    // Subset including arr[l]
    subsetSums(arr, l + 1, r, sum + arr[l]);
    // Subset excluding arr[l]
    subsetSums(arr, l + 1, r, sum);
}

int main()
{
    int arr[] = { 5, 4, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    subsetSums(arr, 0, n - 1);
    return 0;
}
