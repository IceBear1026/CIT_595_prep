Github Course Setup

CIT 5950 uses GitHub for code submission and project collaboration. In the real course, you will register your GitHub username, get access to a private course repo, clone it, work locally, commit, push and submit through Gradescope. 

Github is your source of turth for assignments. 

Typical Flow:
1. git clone <course-repo-url>
2. cd . <repo>

# work on assignment
git status
gid add .
git commit -m "Complete homework"
git push

Then Gradescope may pull from your GitHub repo. 

===
GitHub setup checklist
Before class starts, confirm:
git --version

git config --global user.name "Steven Yang"
git config --global user.email "wodhks1026@gmail.com" 
(Or use your upenn email accordingly)

Check:
git config --global --list

This verifies that your GitHub authentication works
ssh -T git@github.com

SSH key setup
Check if you have a key:
ls ~/.ssh

Look for:
id_ed25519
id_ed25519.pub

If not, create one:
ssh-keygen -t ed25519 -C "wodhks1026@gmail.com"

cat ~/.ssh/id_ed25519.pub

copy this into GitHub:
GitHub -> Settings -> SSH and GPG keys -> New SSH key

Then test: 
ssh -T git@github.com

===
These are Linux commands and tools to be aware of.
make
g++
clang++
gdb
valgrind
clang-format
clang-tidy
POSIX system calls
fork
exec
pipe
dup2
pthread
sockets




