document.addEventListener('DOMContentLoaded', () => {
    const boardElement = document.getElementById('sudoku-board');
    const messageElement = document.getElementById('message');
    const btnGenerate = document.getElementById('btn-generate');
    const btnSolve = document.getElementById('btn-solve');
    const btnClear = document.getElementById('btn-clear');

    let board = Array.from({ length: 9 }, () => Array(9).fill(0));

    // Initialize UI board
    function initBoardUI() {
        boardElement.innerHTML = '';
        for (let r = 0; r < 9; r++) {
            for (let c = 0; c < 9; c++) {
                const input = document.createElement('input');
                input.type = 'text';
                input.maxLength = 1;
                input.className = 'cell';
                input.dataset.row = r;
                input.dataset.col = c;
                input.addEventListener('input', handleInput);
                boardElement.appendChild(input);
            }
        }
    }

    function handleInput(e) {
        const val = e.target.value;
        const r = parseInt(e.target.dataset.row);
        const c = parseInt(e.target.dataset.col);
        
        if (!/^[1-9]$/.test(val)) {
            e.target.value = '';
            board[r][c] = 0;
        } else {
            board[r][c] = parseInt(val);
        }
        messageElement.textContent = '';
    }

    function updateBoardUI() {
        const cells = document.querySelectorAll('.cell');
        cells.forEach(cell => {
            const r = parseInt(cell.dataset.row);
            const c = parseInt(cell.dataset.col);
            const val = board[r][c];
            if (val !== 0) {
                cell.value = val;
                cell.classList.add('read-only');
                cell.readOnly = true;
            } else {
                cell.value = '';
                cell.classList.remove('read-only');
                cell.readOnly = false;
            }
        });
    }

    async function generateBoard() {
        try {
            const response = await fetch('/api/generate');
            if (!response.ok) throw new Error('Failed to generate board');
            const data = await response.json();
            board = data.board;
            updateBoardUI();
            messageElement.textContent = '';
        } catch (error) {
            messageElement.textContent = 'Error connecting to server';
        }
    }

    async function solveBoard() {
        // Collect current board from UI to allow user edits
        const cells = document.querySelectorAll('.cell');
        let tempBoard = Array.from({ length: 9 }, () => Array(9).fill(0));
        cells.forEach(cell => {
            const r = parseInt(cell.dataset.row);
            const c = parseInt(cell.dataset.col);
            tempBoard[r][c] = cell.value ? parseInt(cell.value) : 0;
        });

        try {
            const response = await fetch('/api/solve', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json'
                },
                body: JSON.stringify({ board: tempBoard })
            });

            if (!response.ok) {
                messageElement.textContent = 'Unsolvable board or invalid input';
                return;
            }

            const data = await response.json();
            board = data.board;
            
            // Just update values without making them read-only if they were edited
            cells.forEach(cell => {
                const r = parseInt(cell.dataset.row);
                const c = parseInt(cell.dataset.col);
                cell.value = board[r][c] !== 0 ? board[r][c] : '';
            });
            messageElement.textContent = 'Solved!';
        } catch (error) {
            messageElement.textContent = 'Error connecting to server';
        }
    }

    function clearBoard() {
        board = Array.from({ length: 9 }, () => Array(9).fill(0));
        updateBoardUI();
        const cells = document.querySelectorAll('.cell');
        cells.forEach(cell => {
            cell.classList.remove('read-only');
            cell.readOnly = false;
        });
        messageElement.textContent = '';
    }

    btnGenerate.addEventListener('click', generateBoard);
    btnSolve.addEventListener('click', solveBoard);
    btnClear.addEventListener('click', clearBoard);

    initBoardUI();
});