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
2. Write inside: `41	string	42 42 file` (byte 42 = offset 41, since offsets start at 0)
3. Save and exit
4. Test file: `echo -n "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa42" > test42`
5. Verify: `file -m ft_magic test42` → `test42: 42 file`

# Shell01 — Exercises Walkthrough

Step-by-step solutions for each exercise.

---

## Shebang reminder

`#!/bin/sh` at the top of a script tells the system which interpreter to run it with. Always the first line of every `.sh` file below.

---

## Exercise 01 — print_groups

1. `id -Gn "$FT_USER"` — print all of the user's group names (`-G` = all groups, `-n` = names not numbers)
2. Pipe through `tr ' ' ','` — replace spaces with commas
3. Final command:
   ```bash
   id -Gn "$FT_USER" | tr ' ' ','
   ```
4. `chmod u+x print_groups.sh` — make executable
5. Verify: `export FT_USER=daemon && ./print_groups.sh` → `daemon,bin`

---

## Exercise 02 — find + basename

1. Build the command:
   ```bash
   find . -type f -name "*.sh" -exec basename {} .sh \;
   ```
2. `find .` — search current dir and subdirs
3. `-type f` — only regular files
4. `-name "*.sh"` — only files ending in `.sh` (quoted so the shell doesn't expand it)
5. `-exec basename {} .sh \;` — for each match, strip the path and the `.sh` suffix
6. Save into `find_sh.sh`, `chmod +x find_sh.sh`
7. Verify: `./find_sh.sh | cat -e` → filenames without `.sh`, one per line

---

## Exercise 03 — count_files

1. Build the command:
   ```bash
   find . | wc -l
   ```
2. `find .` — lists `.` itself plus every file/dir recursively
3. `wc -l` — counts the lines (i.e. counts the entries)
4. Save into `count_files.sh`, `chmod u+x count_files.sh`
5. Verify: `./count_files.sh | cat -e` → a number followed by `$`

---

## Exercise 04 — Display MAC addresses

1. Build the command:
   ```bash
   ifconfig | grep ether | awk '{print $2}'
   ```
2. `ifconfig` — show network interface info
3. `grep ether` — keep only lines containing a MAC address
4. `awk '{print $2}'` — print just the address (2nd column)
5. Save into the script, `chmod +x`, then run and verify one MAC per line

---

## Exercise 05 — Tricky filename

1. Escape every shell-special character with `\` before creating the file:
   ```bash
   touch \\\?\$\*\'MaRViN\'\*\$\?\\\"
   ```
2. Verify: `ls` shows the filename (re-quoted by `ls`, but it's the correct literal name)
3. Test read/write: 
   ```bash
   echo 42 > '\?$*'\''MaRViN'\''*$?\"'
   cat '\?$*'\''MaRViN'\''*$?\"'
   ```
4. Confirm output: `42`

---

## Exercise 06 — Skip (print every other line)

1. Build the command:
   ```bash
   ls -l | awk 'NR % 2 == 1'
   ```
2. `ls -l` — list contents, one per line
3. `awk 'NR % 2 == 1'` — `NR` is the line number; the condition keeps only odd-numbered lines (awk prints a line by default when the condition is true)
4. Verify: prints line 1, 3, 5... skips 2, 4, 6...
5. (Alternative) `ls -l | sed -n 'p;n'` — print current line (`p`), skip next (`n`)

---

## Exercise 07 — r_dwssap.sh

Build the pipeline one stage at a time:

1. `cat /etc/passwd` — read the file (`login:password:UID:GID:info:home:shell`)
2. `grep -v '^#'` — remove comment lines (lines starting with `#`)
3. `awk 'NR % 2 == 0'` — keep only even-numbered lines
4. `awk -F: '{print $1}'` — extract just the username (field 1, `:` separated)
5. `rev` — reverse the characters of each username
6. `sort -r` — sort in reverse alphabetical order
7. `sed -n "${FT_LINE1},${FT_LINE2}p"` — keep only the requested line range
8. `tr '\n' ','` — join lines with commas
9. `sed 's/,/, /g'` — add a space after every comma
10. `sed 's/, $/./'` — replace the trailing `, ` with a final `.`
11. `tr -d '\n'` — strip the trailing newline

Final script:
```bash
#!/bin/sh

cat /etc/passwd | grep -v '^#' | awk 'NR % 2 == 0' | awk -F: '{print $1}' \
| rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | tr '\n' ',' \
| sed 's/,/, /g' | sed 's/, $/./' | tr -d '\n'
```

---

## Exercise 08 — add_chelou.sh

Convert two "strange base" numbers, add them, convert back to another strange base.

1. `echo "$FT_NBR1 + $FT_NBR2"` — combine both inputs (quoted to protect special chars)
2. `sed "s/'/0/g"` — convert the `'` symbol of `FT_NBR1`'s alphabet to `0`
3. `tr '\\\"?!' '1234'` — convert the rest of `FT_NBR1`'s symbols (`\`, `"`, `?`, `!`) to digits `1234`
4. `tr 'mrdoc' '01234'` — convert `FT_NBR2`'s alphabet to digits `01234`
5. `xargs echo "ibase=5; obase=13"` — prepend the base-conversion instruction for `bc`
6. `bc` — perform the base-5 addition, output in base 13
7. `tr '0123456789ABC' 'gtaio luSnemf'` — map bc's base-13 digits/letters to the required output symbols

Final script:
```bash
#!/bin/sh

echo "$FT_NBR1 + $FT_NBR2" \
| sed "s/'/0/g" \
| tr '\\\"?!' '1234' \
| tr 'mrdoc' '01234' \
| xargs echo "ibase=5; obase=13" \
| bc \
| tr '0123456789ABC' 'gtaio luSnemf'
```
