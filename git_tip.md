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
