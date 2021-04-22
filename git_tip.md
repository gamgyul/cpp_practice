# GIT TIP

##  BRANCH
브랜치 확인하기  
-------------
깃 브랜치 출력 명령어

* 기본 : `git branch `
* remote : `git branch -r`
* 전체: `git branch -a`
* 정보 출력 옵션: -v


```shell
$ git branch
  devel
* master

$ git branch -r
  origin/master

$ git branch -a
  devel
* master
  remotes/origin/master

$ git branch -av
  devel                 7fb0137 [behind 1] before branching
* master                307013b CMake빌드 수정(Clang compiler물도록) db관련 에러 trycatch문으로 수정 기타 자잘한 cpplint 체크
  remotes/origin/master 8b115ac CMake build

```
브랜치 생성 및 삭제
-------------

브랜치 생성 명령어

```shell
$ git branch btest
```
브랟치 삭제 명령어
```shell
$ git branch -d btest
Deleted branch btest (was 307013b).
```

## LOG

자주쓰는 로그 명령어
```shell
$ git log
```
해당 브랜치의 커밋 내용을 보여준다.


    commit 7fb013794c4a2046767bda10d01d5f42bd175d61 (HEAD -> devel)                                       
    Author: Gamgyul                                                      
    Date:   Tue Apr 9 19:55:17 2019 +0900                                                                              
        before branching                                                                                  
                        
<br/>

```shell
$git log --stat
```
로그 내용에 추가적으로 어떤 파일들이 변경됬는지 표시해준다.

    commit 7fb013794c4a2046767bda10d01d5f42bd175d61 (HEAD -> devel)
    Author: Gamgyul <yunsu.sys@gmail.com>
    Date:   Tue Apr 9 19:55:17 2019 +0900

        before branching

    proj_1/account.cc |  3 ++-
    proj_1/p1.cc      | 13 +------------
     2 files changed, 3 insertions(+), 13 deletions(-)


```shell
$git log --oneline
```
한줄로 표시해준다. 
```shell
$ git log --oneline
7fb0137 (HEAD -> devel) before branching
fec3e4b Merge branch 'testing'
b0978aa 4th test
51f81e4 ipch removed
5b7b183 new commit for branch test
4684a06 (tag: v1.0) 3rd message
f85ec0a 2nd message
4491178 Merge branch 'master' of https://github.com/gamgyul/cpp_practice test
326d452 initial version
db0d1ce Initial commit
```


```shell
$git log --oneline --grapth 
```
브랜치를 그래프로 표시해준다.
```shell
$ git log --oneline --graph
* 7fb0137 (HEAD -> devel) before branching
*   fec3e4b Merge branch 'testing'
|\  
| * 51f81e4 ipch removed
* | b0978aa 4th test
* | 5b7b183 new commit for branch test
|/  
* 4684a06 (tag: v1.0) 3rd message
* f85ec0a 2nd message
*   4491178 Merge branch 'master' of https://github.com/gamgyul/cpp_practice test
|\  
| * db0d1ce Initial commit
* 326d452 initial version
```

```shell
$git log --first-parent 
```
해당 브랜치에서 커밋한 로그만 보여준다. 자주쓰는 옵션이였는데 예를 들어 많은 사람들이 쓰는 devel 브랜치가 있고 내가 쓰는 특정 feature 브랜치가 있다고했을때 feature branch가 devel에서 갈라져나왔다가 다시 devel로 merge를 하는경우가 많을텐데 이때 feature branch에서 커밋했던 내용만 보기위해서 해당 옵션을 사용한다.
```shell
$ git log --oneline --first-parent
7fb0137 (HEAD -> devel) before branching
fec3e4b Merge branch 'testing'
b0978aa 4th test
5b7b183 new commit for branch test
4684a06 (tag: v1.0) 3rd message
f85ec0a 2nd message
4491178 Merge branch 'master' of https://github.com/gamgyul/cpp_practice test
326d452 initial version
```