void sort_stack_100(t_data *db) {
    int pivot1 = find_median(db->sa, db->top_a + 1);
    int pivot2 = find_median_below(db->sa, pivot1, db->top_a + 1);
    int pivot3 = find_median_below(db->sa, pivot2, db->top_a + 1);
    int pushed = 0;

    while (pushed < db->lenght / 2) {
        if (db->sa[db->top_a] <= pivot3) {
            push_b(db);
            pushed++;
        } else if (db->sa[db->top_a] <= pivot2) {
            push_b(db);
            rotate_b(db);  // Rotate stack_b to maintain order
            pushed++;
        } else if (db->sa[db->top_a] <= pivot1) {
            push_b(db);
            pushed++;
        } else {
            rotate_a(db);
        }
    }

    // Sort and merge
    sort_and_merge_b_to_a(db);
}

void sort_and_merge_b_to_a(t_data *db) {
    while (db->top_b >= 0) {
        int max_index = find_largest(db->sb, db->top_b);

        if (max_index == db->top_b) {
            push_a(db);
        } else if (max_index >= db->top_b / 2) {
            while (db->sb[max_index] != db->sb[db->top_b]) {
                rotate_b(db);  // Rotate stack_b until the largest is at the top
            }
            push_a(db);
        } else {
            while (db->sb[max_index] != db->sb[0]) {
                rotate_r_b(db);  // Reverse rotate stack_b
            }
            push_a(db);
        }

        // Combine rotations with stack_a where possible
        if (db->top_a > 0 && db->sa[db->top_a] > db->sa[db->top_a - 1]) {
            rr(db);  // Rotate both stacks
        } else {
            rotate_a(db);
        }
    }

    // Final adjustments to align stack_a
    final_adjustments(db);
}

void final_adjustments(t_data *db) {
    int min_index = find_smallest(db->sa, db->top_a);

    if (min_index <= db->top_a / 2) {
        while (min_index > 0) {
            rotate_a(db);
            min_index--;
        }
    } else {
        while (min_index <= db->top_a) {
            rotate_r_a(db);
            min_index++;
        }
    }
}

#include <stdlib.h>

int find_median(int *stack, int size) {
    int *copy;
    int median;

    // Step 1: Create a copy of the stack
    copy = malloc(size * sizeof(int));
    if (!copy)
        return 0;  // Handle memory allocation error as appropriate

    for (int i = 0; i < size; i++) {
        copy[i] = stack[i];
    }

    // Step 2: Sort the copied stack
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (copy[i] > copy[j]) {
                int temp = copy[i];
                copy[i] = copy[j];
                copy[j] = temp;
            }
        }
    }

    // Step 3: Find the median
    median = copy[size / 2];

    // Step 4: Free the copy and return the median
    free(copy);
    return median;
}


#include <stdlib.h>

int find_median_below(int *stack, int threshold, int size) {
    int *filtered_copy;
    int count = 0;
    int median;

    // Step 1: Create a filtered copy of elements below the threshold
    filtered_copy = malloc(size * sizeof(int));
    if (!filtered_copy)
        return 0;  // Handle memory allocation error as appropriate

    for (int i = 0; i < size; i++) {
        if (stack[i] < threshold) {
            filtered_copy[count] = stack[i];
            count++;
        }
    }

    // Step 2: Sort the filtered copy
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (filtered_copy[i] > filtered_copy[j]) {
                int temp = filtered_copy[i];
                filtered_copy[i] = filtered_copy[j];
                filtered_copy[j] = temp;
            }
        }
    }

    // Step 3: Find the median of the filtered elements
    if (count > 0) {
        median = filtered_copy[count / 2];
    } else {
        median = threshold;  // If no elements are below the threshold, return the threshold itself
    }

    // Step 4: Free the filtered copy and return the median
    free(filtered_copy);
    return median;
}

