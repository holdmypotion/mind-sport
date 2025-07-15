def digit_dp_range(lower, upper, condition_func, state_update_func, is_valid_func, initial_state):
    """
    General Digit DP framework for counting numbers in range [lower, upper] that satisfy a condition

    Parameters:
        -----------
    lower, upper : int
        The range bounds (inclusive)

    condition_func : function(state, digit) -> bool
        Returns whether placing 'digit' is valid given current 'state'

    state_update_func : function(state, digit) -> new_state
        Updates state after placing 'digit'

    is_valid_func : function(state) -> bool
        Checks if final state is valid

    initial_state : any
        Initial state value

    Returns:
        --------
    int : Count of valid numbers in the range
    """
    # Convert bounds to strings for easier digit access
    lower_str = str(lower).zfill(len(str(upper)))
    upper_str = str(upper)

    memo = {}

    def dp(pos, tight_lower, tight_upper, state, started):
        """
        pos: current position
        tight_lower: whether current number is constrained by lower bound
        tight_upper: whether current number is constrained by upper bound
        state: problem-specific state
        started: whether we've started building a non-zero number
        """
        if pos == len(upper_str):
            return 1 if is_valid_func(state) else 0

        key = (pos, tight_lower, tight_upper, state, started)
        if key in memo:
            return memo[key]

        result = 0

        # Determine digit range at current position
        lo = int(lower_str[pos]) if tight_lower else 0
        hi = int(upper_str[pos]) if tight_upper else 9

        # If we haven't started building a number and lo is 0, we can place a 0
        # without marking it as used (leading zero)
        if not started and lo == 0:
            new_tight_lower = tight_lower
            new_state = state  # Leading 0 doesn't change state
            result += dp(pos + 1, new_tight_lower, False, new_state, False)
            lo = 1  # Start next digit iteration from 1

        # Try placing digits in the valid range
        for digit in range(lo, hi + 1):
            # Skip if placing this digit violates our condition
            if not condition_func(state, digit):
                continue

            # Update constraints for next position
            new_tight_lower = tight_lower and (digit == int(lower_str[pos]))
            new_tight_upper = tight_upper and (digit == int(upper_str[pos]))

            # Update state with new digit
            new_state = state_update_func(state, digit)

            # Recurse to next position
            result += dp(pos + 1, new_tight_lower, new_tight_upper, new_state, True)

        memo[key] = result
        return result

    # Start the DP computation
    return dp(0, True, True, initial_state, False)


# Example: Unique Digits Problem Implementation Using The Framework
def count_numbers_with_unique_digits(n):
    if n == 0:
        return 1

    lower = 0
    upper = 10**n - 1

    # Check if digit is not used in the mask
    def condition_func(mask, digit):
        return not ((mask >> digit) & 1)

    # Update mask by marking digit as used
    def state_update_func(mask, digit):
        return mask | (1 << digit)

    # Any final mask is valid
    def is_valid_func(mask):
        return True

    return digit_dp_range(lower, upper, condition_func, state_update_func, is_valid_func, 0)
