<#
  git-push-changes.ps1
  Stages all changes, commits with a simple message, and pushes to the current branch's origin.
  Run this from PowerShell in the project folder: .\git-push-changes.ps1
#>
param(
  [string]$Message = "Add review page, pagination; add DB support and migration scripts"
)

Write-Host "Running Git add, commit, push..."

# show status first
git status

# stage all changes
git add -A

# commit
git commit -m "$Message" -q
if ($LASTEXITCODE -ne 0) {
  Write-Host "Commit failed or nothing to commit. Run 'git status' to inspect." -ForegroundColor Yellow
} else {
  Write-Host "Committed changes."
}

# show branch and remotes
$branch = git branch --show-current
Write-Host "Current branch: $branch"
Write-Host "Remotes:"
git remote -v

# push to origin
Write-Host "Pushing to origin $branch..."
$push = git push origin $branch
if ($LASTEXITCODE -ne 0) {
  Write-Host "Push failed. Check the above output for errors (remote/auth)." -ForegroundColor Red
} else {
  Write-Host "Push succeeded." -ForegroundColor Green
}
