import java.util.*;

public class leetcode {

    public  class TreeNode{
        int val=0;
        TreeNode left;
        TreeNode right;
        TreeNode(){
    
        }
        TreeNode(int val){
            this.val=val;
        }
    }

    Map<TreeNode, TreeNode> parent = new HashMap<>();
    public void constructParentMap(TreeNode root, TreeNode par){
        if(root == null){
            return;
        }
        
        parent.put(root, par);
        constructParentMap(root.left, root);
        constructParentMap(root.right, root);
    }
    public void solve(TreeNode root, int K, List<Integer> list){
        Queue<TreeNode> q = new LinkedList<>();
        HashSet<TreeNode> set = new HashSet<>();
        q.offer(root);
        int level = 0;
        while(!q.isEmpty()){
            int size = q.size();
            while(size-- > 0){
                TreeNode r = q.poll();
                if(r.left != null && !set.contains(r.left)) q.offer(r.left);
                if(r.right != null && !set.contains(r.right)) q.offer(r.right);
                TreeNode par = parent.get(r);
                if(par != null){
                    if(!set.contains(par)){
                        q.add(par);
                        set.add(r);
                    }
                }
            }
            level++;
            if(level == K) break;
        }
        
        while(!q.isEmpty()){
            TreeNode r = q.poll();
            list.add(r.val);
        }
        
    }
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        List<Integer> list = new ArrayList<>();
        if(root == null) return list;
        if(K == 0){
            list.add(target.val);
            return list;
        }
        constructParentMap(root, null);
        solve(target, K, list);
        
        return list;
    }
}