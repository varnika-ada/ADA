import os
import re

for root, dirs, files in os.walk("."):
    for file in files:
        if file.endswith(".cpp"):
            old_path = os.path.join(root, file)

            # remove ALL occurrences of prog_<digits>
            new_name = re.sub(r'prog_\d+', '', file)

            # clean any accidental leftover underscores
            new_name = new_name.lstrip('_')

            new_path = os.path.join(root, new_name)

            if old_path != new_path:
                if not os.path.exists(new_path):
                    os.rename(old_path, new_path)
                    print(f"{file} → {new_name}")
                else:
                    print(f"Skipped (exists): {new_name}")

print("✅ Cleaned all filenames properly")