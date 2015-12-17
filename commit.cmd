@echo off
IF %1.==. GOTO ERROR_MSG

git add -A
git commit -m %*
git config --global credential.helper wincred
git push origin master
GOTO END

:ERROR_MSG
Echo BEINGZERO: Please Specify a Commit Msg

:END