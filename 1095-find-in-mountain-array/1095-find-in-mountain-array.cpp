/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    
    int find(MountainArray &mountainArr){
        int low = 0;
        int high = mountainArr.length()-1;
        
        while(low<high){
            int mid = low + (high - low) / 2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        return low;
    }
    
    int binary(MountainArray &mountainArr, int idx, int target){
        int low = 0;
        int high = idx;
        int ans = -1;
        while(low<=high){
            int mid = low + (high - low) / 2;
            if(mountainArr.get(mid) == target){
                return mid;
            }else if(mountainArr.get(mid) < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return -1;
    }
    
    int binarySearch(MountainArray &mountainArr, int idx, int target){
        int low = idx+1;
        int high = mountainArr.length()-1;;
        while(low<=high){
            int mid = low + (high - low) / 2;
            if(mountainArr.get(mid) == target){
                return mid;
            }else if(mountainArr.get(mid) > target){
                // high = mid-1;
                low = mid+1;
            }else{
                // low = mid+1; 
                high = mid-1;
            }
        }
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int idx = find(mountainArr);
        // cout << idx;
        int left = binary(mountainArr, idx, target);
        if(left!=-1){
            return left;
        }
        return binarySearch(mountainArr, idx, target);
    }
};