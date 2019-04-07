# leetcode-
3-11：9题  
105 前序与中序重建二叉树：dfs递归，每次取前序序列当前下标创建节点，然后在中序序列中找位置，算出左右子树大小，再进一步遍历直到首尾指针相遇  
106 后序与中序重建二叉树：dfs递归，和前序稍有不同，思路基本一样  
109 有序链表转换二叉搜索树：主要难点在找链表中点，可以先遍历计算长度，也可以采用长短步长方法  
114 二叉树展开为链表：思路就是对于每个节点，把它的左子节点放在它和右子节点之间，然后左子节点清空，前序遍历后序遍历都可以，前序遍历的话要保存上一个节点，因为没有父指针，后序不用  
116&117 填充每一个节点的下一个右侧节点指针 dfs递归，要注意非完全二叉树找右侧节点的三种可能情况  
120 三角形最小路径和：动态规划，从大端到小端，动态规划问题是要把大问题拆成小问题先解决再考虑整体，这里一定要是从下往上遍历，从发散端到聚集的一端  
125 验证回文串：没什么技术含量，头尾指针比较  
129 根到叶子节点数字之和：普通的dfs递归，注意从每条路径到数字的转化，遇到叶子节点就把当前生成的数字加给res  
3-12：7题  
123 买股票的最佳时机3：双指针遍历求最大差值  
141 环形链表1：快慢指针，快指针能否追上慢指针  
142 环形链表2：同上  
143 重排链表：双端队列，或者快慢指针分割后后一半逆序插入前一半  
134 加油站：只要总油量大于总消耗，就能走完全程  
135 分发糖果：逐一满足各个条件，左右遍历两次，不满足条件就加糖  
138 复制带随机指针的链表：在原链表中逐个复制，random赋值，链表拆分  
3-13：10题  
124 二叉树的最大路径和：dfs，设置一个全局变量最大和，后序遍历每个结点，用以当前结点为根节点的最大路径和更新全局变量最大和，把以当前结点为非根节点的最大路径和返回上一层  
127 单词接龙：用保存邻接矩阵再bfs的方法很慢，选择使用集合来双向遍历中间碰头，使用到的数据结构是集合  
128 最长连续字串：使用哈希表来实现，用来存储当前每个值对应的最大子序列长度，key是元素值，value初始值为1，根据key-1和key+1是否存在于hashMap中来更新子序列长度  
130 被围绕的区域：逆向思维，遍历四条边找没被围绕的，修改为-，然后将所有不是-的全置为X，把-变回O  
133 克隆图：考察map+dfs，使用map用来检索当前某节点是否已经生成，深度优先遍历，从一个节点开始，先创建新节点并复制节点值，再将该节点存放在map的对应位置，最后填充neighbor  
137 只出现一次的数组2：位运算，所有元素每一位求和存放在32位数组中，每一位%3，得到的从数组头到数组尾组成的二进制数就是所求只出现一次的数  
139 单词拆分：动态规划，定义长度为n+1的数组，其中数组的第i位用来表示字符串的前i个字符能否被拆成字典中的元素，用哈希表构造字典，遍历字符串，更新dp数组，最终返回dp[size]  
150 逆波兰表达式求值：求逆波兰表达式的过程就是数字入栈，遇到符号弹出两个数字运算，结果再入栈，直到数组遍历完，栈顶元素就是结果（此时栈里面也就这一个元素）  
151 翻转字符串里的单词： 先翻转整个链表，再遍历链表，翻转每个单词（由两个指针控制单词的首尾）并加在设置的初始值为空的结果字符串中  
155 最小栈：创建辅助栈s_min用来存储当前的最小元素，最小元素即为栈顶；当辅助栈s_min为空或当前要压入的值小于栈顶值时，将该值压入s_min中，否则压入s_min的栈顶元素  
3-14： 3题  
153&154：寻找旋转排序数组中的最小值：二分查找，注意元素重复时的特殊情况，此时要进行顺序查找  
160 相交链表：两种方法，一种是计算长度，长链表先走差值步，然后长短同时走；还有一种方法是尾部连首部构造环，用快慢指针求解  
3-15： 3题  
147 对链表进行插入排序：插入排序复杂度为O(n^2)，注意插入前要把当前节点和前后都分离，插入后要注意更新当前已排序部分的尾节点和下一个节点   
148 排序链表：要求复杂度O(nlogn)，选择归并排序用递归来做，先用快慢指针将链表一份为二并断开，直到全部分开再按递归顺序两个一组按大小顺序重连起来，一直递归到最后变成两个有序链表合二为一  
162 寻找峰值：题目的定义来说，峰值必然存在，判断完首尾后，进入二分查找，nums[i] > nums[i-1]，在i之后一定存在峰值元素；nums[i] < nums[i-1]，在i之前一定存在峰值元素，要证明就得去看高数了...  
3-16：10题  
164 最大间距：桶排序，先找最大最小元素，确定桶容量为(high-low)/len,则桶个数为(high-low)/桶容量+1，即len+1，然后遍历数组，判断当前数字处在哪个桶内，更新该桶保存的最大值和最小值，然后遍历桶，求相邻非空桶的最大差值  
165 比较版本号：遍历两个字符串，设置两个遍历用来保存当前所在的小版本号的十进制数字形式，比较当前小版本号，比出结果就退出，否则继续比较下一个小版本号，十进制转换由while循环判断和*10+来实现  
167 两数之和：很简单，头尾双指针，比较和与目标值差距，比目标值小头指针后移，比目标值大尾指针前移  
168&171 列表名称和对应数字的转换：一次遍历求就行，唯一注意的是A和1是对应的，字符串转数时字符减完A要加1，数转字符串时除26之前要减1  
172 阶乘后的零：判断5的个数...不说了，主要是要想到这里  
187 重复的DNA序列：把字母定义为值，用两位二进制来表示，构造滑窗和标志矩阵，遍历，标志矩阵中当前滑窗值对应的位为false则置true，为true则将此时的字符串置入unordered_set  
191 位1的个数：n&(n-1)，主要是要知道为什么  
190 颠倒二进制数：一边除一边*+，循环32次  
189 旋转数组：旋转三次来实现，先整体旋转一次，再旋转前k%len个，最后旋转后面其余部分  
3-17：4题    
173 二叉搜索树迭代器：这里类似于一个非递归中序遍历，初始化是把最左路径的元素入栈，然后next函数是弹出当前栈顶元素，并且把栈顶元素右子树的最左路径入栈
174 地下城游戏：动态规划，先初始化末行末列，再依次从右下到左上进行遍历，要注意dp数组的值要大于1，不能为负  
198 打家劫舍：动态规划，当前位置为止能抢到的最大数值与dp数组前两个位置保存的值和nums数组当前位置的值有关  
199 二叉树的右视图：两种方法来实现，一是层序遍历，把每一层最后一个元素入数组，二是前序遍历，记录当前深度，只有当前深度大于res元素个数时将当前节点入res，因为要求是右视图，所以遍历是先右后左  
 3-21 7题  
200 岛屿的个数：遍历二维数组，当当前位置为1时进入递归函数，将与该节点相邻的1都变成0，然后返回主函数后岛屿数加1  
201 数字范围按位与：n&(n-1)，直到n<=m为止，此时的n就是结果，要知道为什么这么做  
202 快乐数：只要不进入循环，就能最终变成1，循环会产生重复，所以可以用快慢指针或者set来实现，遍历完成判断当前值是不是1，输出结果；也可以直接找规律，规律就是只要不是1和4，就继续循环，循环结束后判断当前值是1还是4  
203 移除链表元素：很简单的题，遍历绕过节点值等于要删除数字的节点  
204 计数质数：用素数筛方法，设置长度为n的全1数组，先将前两位置0，从第三位开始遍历处理，到达第i位时，如果值为1，就将从i*i到n之间i的倍数下标对应的值都置0，最后将数组求和就是质数个数，详细见维基百科  
205 同构字符串：定义两个长度为128的标志数组（全0）用来表示到当前为止，某个字母上次出现的时刻，如果对应的两个数组某处值一样，就继续遍历，否则返回false，每次判断成功后要将这两个位置的值置为i+1,即表明出现的时刻  
152 乘积最大子序列：因为有负数存在，所以上一步最小的乘积这一步可能变大（从负到正），所以要维护三个量，最终的最大值max，当前最大值imax，当前最小值imin，当nums[i]为负时交换imin和imax，因为此时imin*nums[i]会变正而imax*nums[i]变负，每一步imax更新为max（imax*nums[i],nums[i]），同理imin  
3-22  8题  
207&210 课程表：考察图的拓扑结构，207题考察图是否为无环有向图，210题多了一步存储节点，为什么要对存储节点的数组翻转要理解  
208&&212 实现字典树：这两道题考察的都是trie树，208题给出了实现思路，实现trie类的构造函数、insert函数、serach函数等，212题是对trie树的应用，用trie树+回溯来解，注意递归终止条件  
209 长度最小的子数组：左右双指针left、right遍历，值大于s后进入次循环，记录当前子数组长度更新最小长度，再left前移去除子数组最左值，直到和小于s，继续加right到right等于数组总长为止  
213 打家劫舍2：两次动态规划，一次0~len-2，一次1~len-1，比较dp1[len-2]和dp2[len-1]  
215 数组中的第k大元素：快排partition函数，配合遍历选取边界  
217 存在重复元素：直接排序找就行...  
3-23 4题  
216 组合总和：典型的回溯递归，注意变量设置和递归退出条件，要满足四个条件，有两个递归退出条件  
217 存在重复元素2：可以用unordered_map实现，遍历数组，如果当前map中存在该元素且两者下标差小于k，就返回true，否则插入该元素  
219 存在重复元素3：217和219都可以用滑窗思想来做，即首先满足小于k的前提，再在滑窗里找符合条件的元素  
222 完全二叉树的节点个数：递归实现，要利用好完全二叉树这个条件：如果某节点左子树的高度和右子树的高度一样，则左子树为满树；如果某节点左子树高度比右子树多1，则右子树为满树  
3-24 9题  
211 添加与搜索单词：构造字典树，相比之下多了一步多了一个正则匹配，也就是在search的时候，如果当前位置是‘.’，说明可以是26个字母中任意一个，跳过该位置去判断后面的单词是否能查找到  
221 最大正方形：这题就是求最大正方形的边长，用动态规划，构造row+1 col+1的二维数组dp，用来更新maxLength   
223 矩阵面积：首先判断两矩形有没有重合，没有重合就直接面积相加，否则要找出重合部分的两个顶点坐标，进而计算重合部分面积，最终返回矩形1面积-重合面积+矩形2面积  
225 用队列实现栈：用两个队列实现栈，保证任意时刻都一个队列为空，若某时刻空队列为q1，非空队列为q2，push时把元素放到非空队列q2中，pop时把其q2前面的q2.size()-1个元素都放入q1中，再弹出弹出q2的back元素，top时直接返回q2的back元素  
231 2的幂：一步得结果，n>0&&(n&(n-1))  
232 用栈实现队列：用两个栈实现队列，s1为辅助栈，s2为主栈，push元素进s1，pop元素从s2出，当pop元素但s2为空时，把s1倒入s2，进栈再出栈顺序不变  
228 汇总区间：遍历数组，主要是对两种不同情况的区分和处理，即连续元素个数大于1和连续元素个数为1（不连续）  
233 数组1的个数：分段解决用到递归思想，每个段内分别讨论最高位和非最高位的情况，根据最高位为1和大于1也分两种情况  
235 二叉搜索树的最近共同祖先：充分利用二叉搜索树的特点，如果root的值在p值和q值中间，说明当前root节点就是最近公共祖先，否则，如果root的值比q值和p值都大，说明p和q都在root的左子树中；如果root的值比q值和p值都小，说明p和q都在root的右子树中  
3-25 14题  
229 众数2：摩尔投票法，类似与出现次数大于一半的数  
	定义两个变量num1和num2，两个计数量count1和count2，用抵消法来做，遍历数组记录num1和num2，再统计核实两数出现的次数是否大于1/3，最后返回  
234 回文链表：三步完成：1.快慢指针找中点；2.后一半链表翻转；3.检查两链表是否一致  
236 二叉树的最近公共祖先：递归实现。  
	如果当前节点的左右子树中分别有一个p和q，则当前节点就是最近公共祖先；  
	如果p和q都在当前节点的左子树中，则left为公共祖先，都在右子树中同理。  
	递归的返回条件就是root为空或root==p或root==q。  
239 除自身以外数组的乘积：  
	考虑保存前缀积，即当前元素左侧元素乘积，迭代式为output[i] = output[i - 1] * nums[i - 1]  
	完成后再考虑后缀积，用变量t实现，t = t*nums[i + 1]，output[i] = output[i] * t  
	最终结果保存再output数组中  
240 滑动窗口的最大值：用deque实现优先队列  
	保存元素下标，遍历数组操作如下：  
	1.如果当前队列非空，且当前元素nums[i]比以队列中的尾元素为下标的数大，则弹出队列中的尾元素，因为这个数不可能会是某个滑窗的最大值  
	2.添加当前值对应的下标  
	3.如果当前下标i减去滑窗大小k大于等于当前最大值的下标，说明此时最大值因为滑窗限制将被清除  
	4.如果当前下标大于等于k-1，可以取滑窗最大值，总共有len-k+1个最大值  
242 有效字母异位词：  
	用一个26位数组统计字符串s中字符出现的次数，对于保存在下标0-25中，下标0存储a出现的次数，以此类推  
	再遍历字符串t，对于的字符在统计数组中相应位置的值中减1  
	最后判断当前的统计数组是否全0  
257 二叉树的所有路径：递归回溯问题，先序遍历二叉树即可  
	前面每个元素都是数字+“->”的形式，到达叶子节点时加上叶子节点值并返回即可  
	一开始做的时候出现问题是因为我在递归函数内部直接做了str+=to_string(root->val)+"->"这样的运算  
	这样的运算是不允许的，因为在这里直接加，后序所有的str中都将含有这一段，而我们要做的是选取不同的路径  
	只需要在下一步递归的入口处（调用递归函数时）修改str即可  
258 各位相加：九余数定理  
	一个数的各位数字之和相加后得到的<10的数字称为这个数的九余数(如果相加结果大于9，则继续相加）  
	假设，数d的根为d%9( 暂时不取0，整除时取9）  
	当d < 10时，1~9这9个数肯定成立;  
	当d >= 10时，d的根为d%9 = (d-1)%9+1，即d的前一个数的数根加1.  
260 只出现一次的数字3: 类似136 只出现一次的数字1  
	还是用异或的方法来求 只不过这次要对数字进行分类，因为有两个只出现一次的数字，所以要想办法把两个数放到两个不同的数组中  
	这两个数组中除了一个出现一次的数字，其他数字都出现两次，此时用136题的方法分别异或两个数组就能得到结果  
	问题就在于如何区分，首先把所有元素异或得到一个数，这个数其实就是两个只出现一次的数的异或结果，从右到左找到该数二进制形式出现的第一个1  
	则这两个数在第一个1出现的下标处的值不同（否则异或应该是0的）  
	根据这一位的值不同，可以把一个数组的元素一分为二  
263 丑数：循环除2、3、5，判断结果是否为1  
264 丑数2：三指针法  
	用空间换时间，保存之前丑数的值，用之前的丑数去计算新的丑数，创建数组，里面的数字都是排好序的丑数，每个丑数都是前面的丑数乘以2、3或5得到的  
	如何确保里面的丑数已经排好序？  
	假设数组中已经有若干排好序的丑数，把最大的记为M  
	考虑把已有的丑数乘2，找到第一个大于M的丑数M1，同理乘3和5，得到M3和M5，M2、M3、M5这三个数的最小值就是下一个丑数  
	但是每一次对所有丑数进行乘运算也比较麻烦，所以定义指针，每次只进行少量的乘法和比较运算，控制指针指向，最终实现寻找丑数  
268 缺失数字：类似只出现一次的数字  
	构造“只出现一次的数字”一题的前提条件：  
	0-n的数字缺一个，数组的下标是0-n-1，数组的大小是n  
	得嘞，这不就是只出现一次的数字吗？  
	我把所有下标异或，再把所有数组中的数异或，再和n异或(因为之前下标是从0-n-1)  
	这个时候我一共异或了一次0-n缺一个，一次0-n一个不缺,缺的那个就是所有异或后的结果  
273 H指数：用桶排序  
	哈希表为hashTable,长度为数组长度+1，遍历数组，如果元素值大于数组长度，则hashTable[size+1]++  
	否则对于的hashTable[citations[i]]++  
	则最终哈希表第i位保存的就是引用数为i的论文的个数，而第size+1位保存的是引用数大于等于size的论文总数  
	从哈希表尾向前遍历，判断当前的值是否大于下标，从i=size开始，如果不大于则更新i-1的值为hashTable[i-1]+hashTable[i]，表示引用数大于等于i-1的论文的总和，直到某时刻hashTable[i] >= i,说明引用数为不少于i的论文最少有i篇  
274 H指数2：本题数组已排序，用二分查找，主要是对不同情况的判断，题读起来有点绕口，注意要找的是满足条件的最大的h  
3-26 4题  
278 第一个错误版本：二分查找  
	计算mid的时候尽量用(end - start) / 2 + start)而不是(end + start) / 2，后者可能会溢出  
	定义变量res用来保存结果值  
279 完全平方数：动态规划或四平方和定理  
	1.动态规划方法：  
	dp[i]表示数字i最少需要几个完全平方数来表示，dp[i]=min(dp[i-j*j])+1,  
	遍历数组更新dp数组，每一步在满足i-k为完全平方数的k中找最小的dp[k],dp[i]=dp[k]+1  
	2.四平方和法：  
	根据 拉格朗日四平方和定理，可以得知答案必定为 1, 2, 3, 4 中的一个。  
	首先根据勒让德三平方和定理，可以得知当 n=4^a *(8b+7)时，n为4；  
	然后再通过循环判断是否为1或2  
	若都不是则答案为 3。  
283 移动零：简单的遍历数组  
	核心在于定义新指针来重排数组元素，便利一次数组，只依次加入非零元素，再将数组后面位置清零  
284 顶端迭代器：重点在于对变量isPeek和value的维护  
	在class Iterator的基础上设计一个class PeekingIterator。主要是增加一个peek()方法。该方法获得和调用next()一样的值，但是迭代器不移动。  
	next和hasNext可以通过调用Iterator类实现，则新类中需要做的就是定义一个标记，isPeek用来表示上一步为peek操作，value记录值  
	如果上一步为peek操作，那么next返回的就是value值，否则直接调用原next函数,注意此时isPeek将失效，因为保存的值为value的元素已经弹出了  
	如果上一步为peek操作，那么hasNext返回的就是true，因为刚peek完说明还有元素在，否则直接调用原hasNext函数  
	peek操作时，如果上一步为peek，那说明peek了两次，第二次可以直接用第一次的结果，否则，置isPeek为true，返回原next的值给value，返回value  
287 寻找重复数：二分查找  
	为什么要说另类呢？因为之前见到的二分查找都是以位置的中点为基准来进行查找  
	这道题数字是无序的，但是取值在1-n之间  
	可以对取值进行二分查找，定义两个指针分别指向1和n  
	每次以中间值mid为参考，用count记录整个数组中不大于中间值的数字的多少、  
	如果这个count不大于mid，就说明不大于mid的数中肯定是没有重复的，而重复的数肯定比mid大  
	如果count大于mid，则重复数组肯定比mid小，因为如果不重复不大于mid1的数最多有mid个(从1到mid)  
3-27：3题  
289 生命游戏：重点在于如何实现“同步”，标记中间量  
	因为题目要求的是同时变化，而实际操作只能遍历数组来实现，所以修改的值不能影响下一步的操作  
	所以这里选择将由dead变为live的细胞置为3，由live变dead的细胞置为2  
	这样就不会影响到后面的变换，最终只需要遍历数组将3变成1，将2变成0即可  
290 单词模式：判断字符和单词能否实现一一映射  
	方法一：自己的渣渣方法  
	首先把str字符串分割成单词,存放在数组s中  
	然后以pattern[i]为键以s[i]为值进行一次插入，如果当前存在key值但是map[key]不等于当前的s[i],返回false，如果key值不存在则插入(pattern[i],s[i])  
	再以以s[i]为键以pattern[i]为值进行一次插入,同上  
	为什么要插入判断两次，因为要保证对应关系，需要a能映射到b，b也能映射到a  
	方法二：大佬的方法  
	思路基本上都差不多  
	这里用istringstream来实现分割...之前没接触过  
	后序的处理用到了如下思想：  
	将字母和单词分别映射成int，当某一对(char,string)出现时，分别修改当前map1中char的值和map2中string的值  
	因为是顺序遍历，所以当char和string一一对应时，无论如何map1中char的值等于map2中string的值  
	只要不一样，就说明这两者其中一个陷入了其他的对应关系，在两者不同时出现的某一次遍历中值被修改  
295 数据流的中位数：剑指offer有类似题，用最大最小堆来实现，具体的算法复杂度比较在代码里有，底层可以直接用优先队列，也可以用vector  
	维护一个最大堆和最小堆，最小堆中任意一个数都大于最大堆中最大的数  
	假设总数为偶数时，新数据会被插入到最小堆中，总数变为奇数，那么此时中位数就是最小堆的头  
	总数为奇数时，新数据插入到最大堆，总数变为偶数，中位数就是最大堆和最小堆的头元素的平均数  
4-2 3题  
297 二叉树的序列化和反序列化：  
	有递归先序方法和非递归方法选择，但是实际验证发现递归方法会超时  
	非递归方法的序列化通过一个队列来实现，层序遍历  
	反序列化则先将字符串序列转为数组，再根据未知关系递归重建二叉树  
299 猜数字游戏：  
	这道题其实很简单，难的地方在于读懂题意...  
	bulls数很好找，只要两字符串对应位置相等，就ok  
	cows数通过两个哈希表来实现，分别记录每个数字出现的次数  
	最终每个数字出现的次数由两哈希表对应位置较小的数来确定  
	cows和bulls对立的，即bulls则肯定不是cows，所以通过ifelse分支来实现  
300 最长上升子序列：动态规划问题  
	有两种构造dp数组的方式，一种是常见的，dp[i]表示到第i位为止的最大上升子序列  
	要获得这个值，就要把nums[0]~nums[i-1]所有的数和nums[i]比较，  
	如果nums[j]小于nums[i]且j<i，就更新当前dp[i]为max(dp[i],dp[j]+1)  
	最后遍历dp找最大值即可  
	方法二:复杂度o(nlogn)  
	定义长度为数组长度的数组dp,其中dp[i]表示所有长度为i+1的递增子序列中，最小的序列尾数  
	则dp数组一定是递增数组，可以用maxLen来表示当前最长递增子序列的长度  
	对数组进行迭代，依次判断将每个数插入dp数组中的相应的位置：  
	1. num > dp[maxLen], 表示num比所有已知递增序列的尾数都大, 将num添加入dp数组尾部, 并将最长递增序列长度maxL加1  
	2. dp[i-1] < num <= dp[i], 只更新相应的dp[i]=num  
	遍历完数组后得到的maxLen就是结果  
  
4-3 3题  
303&304 区域检索-数组不可变：构造变量存储中间值  
	分别用等长数组和等大矩阵来保存前缀和，那么每次求部分和只需要取值而不需要计算  
307 区域检索-数组可变：线段树和树状数组都可以，树状数组更简单一点  
	因为不好理解，具体的过程看代码注释  
	相对来说这道题用树状数组更简单一些  
4-4 2题  
308 最佳买卖股票含冷冻期  
	股票系列的题目都是用动态规划来解决的，但根据实际情况的不同，需要保存的中间状态量的多少也不尽相同  
	比如这道含冷冻期的最佳买卖股票策略，如果构造三个状态数组sell，buy和cool，那么后序的处理会好理解很多：  
	sell[i]表示截至第i天，最后一个操作是卖时的最大收益；  
	buy[i]表示截至第i天，最后一个操作是买时的最大收益；  
	cool[i]表示截至第i天，最后一个操作是冷冻期时的最大收益；  
	递推公式：  
	sell[i] = max(buy[i-1]+prices[i], sell[i-1]) (第一项表示第i天卖出，第二项表示第i天冷冻)  
	buy[i] = max(cool[i-1]-prices[i], buy[i-1]) （第一项表示第i天买进，第二项表示第i天冷冻）  
	cool[i] = sell[i-1]  
	按照这个来就ok  
	但是，如果不是按照这个来做的，理解起来就会复杂很多，而且复杂度也会边高  
	定义数组dp用来保存中间值，其中dp[i]表示到第i天为止的最高收益  
	每一步的dp[i]都需要遍历当前数组来求  
	首先考虑第i-1天没卖出股票的情况，令dp[i]=dp[i-1]  
	dp[i-1]表示当在第i-2天最后一次卖出股票时第i天的收益(第i-1天冻结)  
	接着遍历所有在第i-1天卖出股票的情况，令j=i-1~1,当prices[i-1]>prices[j-1]时，说明第j-1天买入第i-1天卖出有的赚，这种情况下的收益为  
	dp[j-2]+price[i-1]-price[j-1],其中dp[j-2]表示第j-2天的收益，如果j大于2取dp[j-2]，否则取0  
	i从2到size，j从i-1到0，复杂度o(n*n)，遍历整个数组后dp[size]表示最大收益  
312 戳气球：同样是一道动态规划题  
	定义二维数组dp，dp[i][j]表示从i到j的可以获得的最大硬币  
	递推式是dp[i][j] = max(dp[i][j], nums[k] * right*left + before + after);  
	其中right和left分别是nums[i-1]和nums[j+1]，k表示i到j之间最后一个戳破的气球的位置  
	before表示dp[i][k-1],after表示dp[k+1][j]  
	这道题的核心就是一个三重循环，第一层确定区间长度，第二层确定起点终点，第三层找dp[i][j]的最大值，通过区间的合并来实现  
4-5 1题  
313 超级丑数：多指针法，很像264题，也就是剑指offer49题  
	不同的是这道题的因子是以数组形式给出的，所以要构造一个数组用来存储每个因子当前指向的是已列出丑数数组的哪个位置  
	也就是说这个数组存的都是"指针"，标记当前因子primes[i]指向的位置  
	思路和264题丑数一致，只不过这里给的因子是列表给出并不确定  
	那么需要和264题一样构造指针，有多少个因子就构造多少个，保存在数组p中，初始值都为0  
	其中p[index]表示当前因子prime[i]的指针，类似于264题中的mutiply2、mutiply3和mutiply5  
	定义uglyNumber数组长度为n，第一个数为1，所有的指针p[i]初始状态都指向0  
	开始遍历，每一步分三步进行：  
	1.查找下一个丑数，这个数是min(primes[i]*uglyNumbers[p[index]]),i从0到primes.size()  
	2.更新uglyNumbers[nextUglyIndex]  
	3.更新指针的指向，当primes[i]*uglyNumbers[p[index]等于最小值时，将p[index]++,使其表示的下标前进1位  
4-6 2题  
318 最大单词长度乘积:利用每个位置的有限选择构造哈希表，这道题中每个“单词”中出现的只有26个可能，用26位二进制表示  
	将words中每个元素都转换成一个26位二进制数，维护一个最大长度积res初值为0两层循环  
	i取0到words.size(),j取i+1到words.size(),判断对应位置的数字value[i]和value[j]相与是否为0  
	若为0则说明words[i]和words[j]没有重复，记录其长度乘积用于维护res  
	遍历完毕则res中保存的就是题目要求的结果  
315 计算右侧小于当前元素的个数：下标与值映射+归并思想，排序号+树状数组，构造二叉搜索树均可  
	具体的解析见代码，这道题主要考察的就是o(nlogn)复杂度的实现，在构造有序的过程中记录个数  
