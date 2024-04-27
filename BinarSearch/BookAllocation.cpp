/*
You have N books, each with A[i] number of pages. M students need to be allocated contiguous books,
 with each student getting at least one book.
Out of all the permutations, the goal is to find the permutation where the sum of maximum number of pages in a
book allotted to a student should be minimum, out of all possible permutations.

Note: Return -1 if a valid assignment is not possible,
 and allotment should be in contiguous order (see the explanation for better understanding).
Example 1:

Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output:113
Explanation:Allocation can be done in
following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90} Maximum Pages =113.
Therefore, the minimum of these cases is 113,
which is selected as the output.
*/
class Solution
{
public:
    // Function to find the minimum number of pages needed for given constraints.
    int findRange(int A[], int N, int mid)
    {
        int students = 1; // Initialize the number of students to 1.
        int sum = 0;      // Initialize the sum of pages read by current student to 0.

        for (int i = 0; i < N; i++)
        {
            // Check if adding the current book's pages exceeds the limit 'mid'.
            if (sum + A[i] > mid)
            {
                students++; // Increment student count as a new student is needed.
                sum = 0;    // Reset sum for the new student.
            }
            sum += A[i]; // Add the current book's pages to the current student's total.
        }
        return students; // Return the total number of students required for 'mid' pages.
    }

    // Function to find the minimum number of pages each student should read.
    int findPages(int A[], int N, int M)
    {
        // If the number of students is more than the number of books, it's not possible.
        if (M > N)
            return -1; // Return -1 indicating invalid input.

        int low = A[N - 1]; // Initialize the lower bound as the pages of the largest book.
        int high = 0;       // Initialize the upper bound as 0 (no books read).

        // Calculate the total pages in all books for setting the upper bound.
        for (int i = 0; i < N; i++)
        {
            high += A[i]; // Sum up the pages of all books.
        }

        int mid, ans = 0; // Initialize variables for binary search and storing result.

        // Perform binary search to find the minimum pages that can be allocated to each student.
        while (low <= high)
        {
            mid = low + (high - low) / 2; // Calculate the middle value.

            int students = findRange(A, N, mid); // Get the number of students needed for 'mid' pages.

            if (students > M)
            {
                low = mid + 1; // If more students are needed, adjust the lower bound.
            }
            else
            {
                high = mid - 1; // If fewer or equal students are needed, adjust the upper bound.
                ans = mid;      // Update the answer to the current mid value.
            }
        }

        return ans; // Return the minimum pages that can be allocated to each student.
    }
};
