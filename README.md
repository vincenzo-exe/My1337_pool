# Shell00 — Exercises Walkthrough

Step-by-step solutions for each exercise.

---

## Exercise 00 — the `z` file

1. `echo "Z" > z` — creates `z` containing `Z` + newline (`echo` appends `\n` by default, `>` overwrites/creates the file)
2. Verify: `cat z` → prints `Z`

---

## Exercise 01 — testShell00

1. `truncate -s 40 testShell00` — set exact size to 40 bytes
2. `chmod 455 testShell00` — set permissions to `-r--r-xr-x`
3. `touch -ct 06012342 testShell00` — set timestamp to June 1, 23:42
4. `tar -cf testShell00.tar testShell00` — archive it
5. Verify: `ls -l testShell00` and extract test with `tar -xpf testShell00.tar` (`-p` preserves perms/timestamps)

---

## Exercise 02 — test0 → test6

1. `mkdir test0 test2` / `touch test1 test3 test4` — create files & dirs
2. `truncate -s 4 test1`, `truncate -s 1 test3`, `truncate -s 2 test4` — set sizes
3. `ln test3 test5` — create hard link
4. `ln -s test0 test6` — create symbolic link
5. `chmod 715 test0`, `chmod 714 test1`, `chmod 504 test2`, `chmod 404 test3`, `chmod 641 test4` — set permissions (`test5` inherits `test3`'s automatically)
6. `touch -ct 06012047 test0`, `touch -ct 06012146 test1`, `touch -ct 06012245 test2`, `touch -ct 06012344 test3`, `touch -ct 06012343 test4` — set timestamps (`test5` inherits `test3`'s)
7. `touch -h -a -m -t 202406012220 test6` — set symlink's own timestamp
8. Verify: `ls -l` and `ls -li` (`test3`/`test5` share the same inode)
9. `tar -cf exo2.tar *` — archive everything
10. (optional cleanup) `rm -rf test0 test1 test2 test3 test4 test5 test6`

---

## Exercise 03 — SSH key

1. `ssh-keygen -t rsa -b 4096` — generate a 4096-bit RSA key pair
2. Press Enter to accept default save location
3. Press Enter twice for an empty passphrase
4. `ls ~/.ssh` — confirm `id_rsa` and `id_rsa.pub` exist
5. `cp ~/.ssh/id_rsa.pub id_rsa_pub` — copy public key into exercise folder
6. `cat id_rsa_pub` — confirm it starts with `ssh-rsa AAAAB3...`
7. `ls` — confirm only `id_rsa_pub` is present (never the private key)
8. `git add ex03/id_rsa_pub && git commit -m "Add SSH public key" && git push`

---

## Exercise 04 — midLS

1. Write the command: `ls -tmp` (`-t` sort by mtime, `-m` comma-separated, `-p` trailing `/` on dirs)
2. `echo "ls -tmp" > midLS` — save it into the file
3. Verify: `cat midLS`

---

## Exercise 05 — git log / cat -e

1. `git log -n 5 --format=%h` — show short hashes of the last 5 commits
2. `echo "hello" > test && echo "world" >> test` — build test file (if needed for the exercise)
3. `cat -e test` — show line endings as `$`

---

## Exercise 06 — git_ignore.sh

1. `nano git_ignore.sh` — create the script
2. Write inside:
   ```bash
   #!/bin/bash
   git ls-files -io --exclude-standard
   ```
3. Save (Ctrl+O, Enter) and exit (Ctrl+X)
4. `chmod u+x git_ignore.sh` — make it executable
5. `./git_ignore.sh` — run and verify output

---

## Exercise 07 — diff/patch

1. `cp a b` — duplicate the original file
2. `echo "x" >> b` — make `b` differ from `a`
3. `diff a b > sw.diff` — generate the patch file
4. Verify: `cat sw.diff` shows the diff
5. (optional check) `patch a < sw.diff` should reproduce `b` from `a`

---

## Exercise 08 — find

1. Write the command into `clean`:
   ```bash
   find . -type f \( -name "*~" -o -name "#*#" \) -print -delete
   ```
2. `chmod u+x clean` if it needs to be executable
3. Test: create dummy files (`touch file~ '#file#'`) then run `./clean` or the command directly
4. Verify: files are printed then deleted

---

## Exercise 09 — ft_magic

1. `nano ft_magic` — create the magic file
2. Write inside: `41	string	42	42 file` (byte 42 = offset 41, since offsets start at 0)
3. Save and exit
4. Test file: `echo -n "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa42" > test42`
5. Verify: `file -m ft_magic test42` → `test42: 42 file`
