start_val = 5
dest_val = 1

def find_lca(node):
    if not node:
        return None

    if node.val == startValue or node.val == destValue:
        return node

    left_lca = find_lca(node.left)
    right_lca = find_lca(node.right)

    if left_lca and right_lca:
        return node

    return left_lca if left_lca else right_lca


