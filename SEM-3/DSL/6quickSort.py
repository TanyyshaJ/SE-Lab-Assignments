class QuickSort:
    def partition(self, arr, low, high):
        pivot = arr[high]
        i = low - 1
        for j in range(low, high):
            if arr[j] <= pivot:
                i += 1
                arr[j], arr[i] = arr[i], arr[j]

        arr[i + 1], arr[high] = arr[high], arr[i + 1]
        return i + 1

    def quicksort(self, arr, low, high):
        if low < high:
            pi = self.partition(arr, low, high)
            self.quicksort(arr, low, pi - 1)
            self.quicksort(arr, pi + 1, high)

    def sort(self, arr):
        self.quicksort(arr, 0, len(arr) - 1)
        return arr


# Example Usage:
if __name__ == "__main__":
    nums = [10, 80, 30, 90, 40]
    quick_sort_instance = QuickSort()
    
    sorted_nums = quick_sort_instance.sort(nums)
    
    print("Sorted Array:")
    for x in sorted_nums:
        print(x, end=" ")
