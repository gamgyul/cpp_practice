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

기타 브랜치 명령어
---------------
`git branch -u origin/master` : 현재 브랜치를 remote의 origin/master와 연결한다.

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

## CONFIG

옵션 범위 설정
-------------
git config에서 설정하는 범위는 3가지이고 다음과같다.

1. `/etc/gitconfig` : 모둔 사용자에 적용되는 설정이다. `--system`로 사용한다. \
옵션의 경우 루트 사용자 권한이있어야 수정 가능하다.
2. `~/.gitconfig` : 현재 사용자에게 설정된다. `--global` 로 사용한다. 
3. `.git/config` : 현재 directory의 저장소에만 적용이된다. `--local`옴션 혹은 옵션을 따로 적용하지 않으면 설정된다.

옵션의 경우 3 > 2 > 1 순으로 우선순위로 적용된다.

git에서 많이 사용하는 옵션.
------------------------
### 설정 확인
```
    $ git config --global -l
```
### 사용자 정보
```
    $ git config --global user.name "John Doe"
    $ git config --global user.email johndoe@example.com
```
### ALIAS
* 기본 명령어 alias
```
    $ git config --global alias.co checkout
    $ git config --global alias.br branch
    $ git config --global alias.ci commit
    $ git config --global alias.st status
    $ git config --global alias.lg "log --oneline --decorate --graph --all"
```
### merge 관련 옵션
저장소에 올라간 코드를 rebase를 하는경우 문제가 생길 수 있기 때문에
기본적으로 pull 할때는 미리 rebase를 하는것이 좋다.
``` 
    $ git config --global pull.rebase true

    // 특정 브랜치를 rebase
    $ $ git config branch.{BRANCH-NAME}.rebase true
```
프로젝트내에서 이력관리를 위해서 fast foward를 강제로 막고 머지 커밋을 하는 no -ff 옵션 설정\
[--no-ff 를 사용하는 이유에 대해 말해주는 branching model 글](https://nvie.com/posts/a-successful-git-branching-model/)

```
    $ git config --global branch.{BRANCH-NAME}.mergeoptions "--no-ff"
```

