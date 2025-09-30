// used HTML for the Landing Page 
// NOT FULLY DONE YET!

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>MediCare Pharmacy Management System</title>
    <style>
        /* General Reset */
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: 'Inter', sans-serif;
        }

        /* Body and Layout */
        body {
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            min-height: 100vh;
            padding: 20px;
        }

        .container {
            max-width: 1400px;
            margin: 0 auto;
        }

        /* Toast Notification Styling */
        #toastContainer {
            position: fixed;
            top: 20px;
            right: 20px;
            z-index: 2000;
            max-width: 350px;
        }
        .toast {
            padding: 15px;
            border-radius: 8px;
            margin-bottom: 10px;
            box-shadow: 0 4px 12px rgba(0,0,0,0.15);
            font-weight: 600;
            opacity: 0;
            transform: translateX(100%);
            transition: opacity 0.5s ease-in-out, transform 0.5s ease-in-out;
        }
        .toast.show {
            opacity: 1;
            transform: translateX(0);
        }
        .toast-success {
            background: #c6f6d5;
            color: #22543d;
            border-left: 4px solid #48bb78;
        }
        .toast-danger {
            background: #fed7d7;
            color: #742a2a;
            border-left: 4px solid #f56565;
        }
        .toast-warning {
            background: #feebc8;
            color: #7c2d12;
            border-left: 4px solid #ed8936;
        }

        /* Header Styling */
        .header {
            background: white;
            padding: 30px;
            border-radius: 15px;
            box-shadow: 0 10px 30px rgba(0,0,0,0.2);
            margin-bottom: 30px;
            text-align: center;
        }

        .header h1 {
            color: #667eea;
            font-size: 2.5em;
            margin-bottom: 10px;
        }

        .header p {
            color: #666;
            font-size: 1.1em;
        }

        /* Stats Cards */
        .stats-container {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));
            gap: 20px;
            margin-bottom: 30px;
        }

        .stat-card {
            background: white;
            padding: 25px;
            border-radius: 15px;
            box-shadow: 0 5px 15px rgba(0,0,0,0.1);
            text-align: center;
            transition: transform 0.3s;
        }

        .stat-card:hover {
            transform: translateY(-5px);
        }

        .stat-card h3 {
            color: #666;
            font-size: 0.9em;
            margin-bottom: 10px;
            text-transform: uppercase;
        }

        .stat-card .number {
            font-size: 2.5em;
            font-weight: bold;
            color: #667eea;
        }

        .main-content {
            display: grid;
            grid-template-columns: 1fr 1fr;
            gap: 30px;
        }

        /* Panels */
        .panel {
            background: white;
            padding: 30px;
            border-radius: 15px;
            box-shadow: 0 10px 30px rgba(0,0,0,0.2);
        }

        .panel h2 {
            color: #667eea;
            margin-bottom: 20px;
            padding-bottom: 10px;
            border-bottom: 3px solid #667eea;
            font-size: 1.8em;
        }

        /* Forms */
        .form-group {
            margin-bottom: 15px;
        }

        .form-group label {
            display: block;
            margin-bottom: 5px;
            color: #333;
            font-weight: 600;
        }

        .form-group input, .form-group select {
            width: 100%;
            padding: 12px;
            border: 2px solid #e0e0e0;
            border-radius: 8px;
            font-size: 1em;
            transition: border-color 0.3s;
        }

        .form-group input:focus, .form-group select:focus {
            outline: none;
            border-color: #667eea;
        }

        /* Buttons */
        .btn {
            padding: 12px 20px;
            border: none;
            border-radius: 8px;
            font-size: 1em;
            font-weight: 600;
            cursor: pointer;
            transition: all 0.3s;
            margin-right: 10px;
            margin-top: 10px;
            box-shadow: 0 4px 6px rgba(0,0,0,0.1);
        }
        .btn-sm {
            padding: 6px 10px;
            font-size: 0.85em;
            margin: 0 5px 0 0;
            box-shadow: none;
        }

        .btn-primary {
            background: #667eea;
            color: white;
        }

        .btn-primary:hover {
            background: #5568d3;
            transform: translateY(-2px);
            box-shadow: 0 5px 15px rgba(102, 126, 234, 0.4);
        }

        .btn-success {
            background: #48bb78;
            color: white;
        }

        .btn-success:hover {
            background: #38a169;
            transform: translateY(-2px);
        }

        .btn-danger {
            background: #f56565;
            color: white;
        }

        .btn-danger:hover {
            background: #e53e3e;
            transform: translateY(-2px);
        }

        .btn-warning {
            background: #ed8936;
            color: white;
        }

        .btn-warning:hover {
            background: #dd6b20;
            transform: translateY(-2px);
        }

        /* Inventory Table */
        .inventory-table {
            width: 100%;
            overflow-x: auto;
            margin-top: 20px;
        }

        table {
            width: 100%;
            border-collapse: collapse;
            min-width: 700px; /* Ensure table is readable on small screens */
        }

        th, td {
            padding: 12px;
            text-align: left;
            border-bottom: 1px solid #e0e0e0;
            vertical-align: middle;
        }

        th {
            background: #f7fafc;
            color: #667eea;
            font-weight: 600;
        }

        tr:hover {
            background: #f7fafc;
        }

        /* Cart Display */
        .cart-item {
            background: #f7fafc;
            padding: 15px;
            border-radius: 8px;
            margin-bottom: 10px;
            display: flex;
            justify-content: space-between;
            align-items: center;
        }

        .cart-item-info {
            flex-grow: 1;
        }

        .cart-item-info h4 {
            color: #333;
            margin-bottom: 5px;
        }

        .cart-item-info p {
            color: #666;
            font-size: 0.9em;
        }

        .remove-btn {
            background: #f56565;
            color: white;
            border: none;
            padding: 8px 15px;
            border-radius: 5px;
            cursor: pointer;
            font-size: 0.9em;
        }

        .remove-btn:hover {
            background: #e53e3e;
        }

        /* Invoice Display */
        .invoice {
            background: white;
            padding: 30px;
            border-radius: 15px;
            box-shadow: 0 10px 30px rgba(0,0,0,0.2);
            margin-top: 30px;
            display: none;
        }

        .invoice-header {
            text-align: center;
            border-bottom: 3px solid #667eea;
            padding-bottom: 20px;
            margin-bottom: 20px;
        }

        .invoice-header h2 {
            color: #667eea;
            font-size: 2em;
        }

        .invoice-details {
            margin-bottom: 20px;
        }

        .invoice-table {
            width: 100%;
            margin-bottom: 20px;
        }

        .invoice-total {
            text-align: right;
            font-size: 1.5em;
            font-weight: bold;
            color: #667eea;
            padding-top: 20px;
            border-top: 3px solid #667eea;
        }

        .low-stock {
            color: #f56565;
            font-weight: bold;
        }

        .search-box {
            margin-bottom: 20px;
        }

        .search-box input {
            width: 100%;
            padding: 12px;
            border: 2px solid #e0e0e0;
            border-radius: 8px;
            font-size: 1em;
        }

        /* Generic Modal */
        .modal {
            display: none;
            position: fixed;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background: rgba(0,0,0,0.5);
            z-index: 1000;
            justify-content: center;
            align-items: center;
        }

        .modal-content {
            background: white;
            padding: 30px;
            border-radius: 15px;
            max-width: 500px;
            width: 90%;
            max-height: 80vh;
            overflow-y: auto;
            box-shadow: 0 10px 40px rgba(0,0,0,0.3);
            animation: fadeIn 0.3s ease-out;
        }
        @keyframes fadeIn {
            from { opacity: 0; transform: translateY(-20px); }
            to { opacity: 1; transform: translateY(0); }
        }

        .close-modal {
            float: right;
            font-size: 1.8em;
            cursor: pointer;
            color: #aaa;
        }

        .close-modal:hover {
            color: #333;
        }

        /* Responsive Layout */
        @media (max-width: 768px) {
            .main-content {
                grid-template-columns: 1fr;
            }
        }

        .import-section {
            margin-top: 30px;
            padding: 20px;
            background: #f7fafc;
            border-radius: 8px;
            border: 1px solid #e0e0e0;
        }

        /* Loading Spinner */
        .loading {
            display: none;
            text-align: center;
            padding: 20px;
        }

        .spinner {
            border: 4px solid #f3f3f3;
            border-top: 4px solid #667eea;
            border-radius: 50%;
            width: 40px;
            height: 40px;
            animation: spin 1s linear infinite;
            margin: 0 auto;
        }

        @keyframes spin {
            0% { transform: rotate(0deg); }
            100% { transform: rotate(360deg); }
        }
    </style>
</head>
<body>
    <!-- Custom Toast Container -->
    <div id="toastContainer"></div>

    <div class="container">
        <!-- Header -->
        <div class="header">
            <h1>🏥 MediCare Pharmacy Management System</h1>
            <p>Complete OOP-Based Medicine & Inventory Management Solution</p>
        </div>

        <!-- Statistics Dashboard -->
        <div class="stats-container">
            <div class="stat-card">
                <h3>Total Medicines</h3>
                <div class="number" id="totalMedicines">0</div>
            </div>
            <div class="stat-card">
                <h3>Total Sales</h3>
                <div class="number" id="totalSales">৳0.00</div>
            </div>
            <div class="stat-card">
                <h3>Medicines Sold</h3>
                <div class="number" id="medicinesSold">0</div>
            </div>
            <div class="stat-card">
                <h3>Low Stock Items</h3>
                <div class="number low-stock" id="lowStock">0</div>
            </div>
        </div>

        <!-- Main Content -->
        <div class="main-content">
            <!-- Left Panel: Add Medicine & Import -->
            <div class="panel">
                <h2>📦 Medicine Management</h2>
                
                <!-- Add Medicine Form -->
                <div class="form-group">
                    <label for="medID">Medicine ID</label>
                    <input type="text" id="medID" placeholder="e.g., MED001">
                </div>
                <div class="form-group">
                    <label for="medName">Medicine Name</label>
                    <input type="text" id="medName" placeholder="e.g., Paracetamol">
                </div>
                <div class="form-group">
                    <label for="genericName">Generic Name</label>
                    <input type="text" id="genericName" placeholder="e.g., Acetaminophen">
                </div>
                <div class="form-group">
                    <label for="manufacturer">Manufacturer</label>
                    <input type="text" id="manufacturer" placeholder="e.g., Square Pharmaceuticals">
                </div>
                <div class="form-group">
                    <label for="price">Price (৳)</label>
                    <input type="number" id="price" placeholder="0.00" step="0.01">
                </div>
                <div class="form-group">
                    <label for="stock">Stock Quantity</label>
                    <input type="number" id="stock" placeholder="0" min="0">
                </div>
                <div class="form-group">
                    <label for="expiryDate">Expiry Date</label>
                    <input type="date" id="expiryDate">
                </div>
                <div class="form-group">
                    <label for="category">Category</label>
                    <select id="category">
                        <option value="Tablet">Tablet</option>
                        <option value="Capsule">Capsule</option>
                        <option value="Syrup">Syrup</option>
                        <option value="Injection">Injection</option>
                        <option value="Ointment">Ointment</option>
                        <option value="Drop">Drop</option>
                    </select>
                </div>
                
                <button class="btn btn-primary" onclick="addMedicine()">➕ Add Medicine</button>
                <button class="btn btn-success" onclick="generateRandomMedicine()">🎲 Generate Random</button>
                
                <!-- Import Section -->
                <div class="import-section">
                    <h3 style="color: #667eea; margin-bottom: 15px;">🌐 Import from Medex</h3>
                    <p style="color: #666; margin-bottom: 10px; font-size: 0.9em;">Simulate importing medicine data from an external source (medex.com.bd)</p>
                    <button class="btn btn-warning" onclick="importFromMedex()">📥 Import Sample Medicines</button>
                    <div class="loading" id="importLoading">
                        <div class="spinner"></div>
                        <p style="margin-top: 10px; color: #667eea; font-weight: 600;">Importing medicines...</p>
                    </div>
                </div>
            </div>

            <!-- Right Panel: Sales & Cart -->
            <div class="panel">
                <h2>🛒 Sales & Billing</h2>
                
                <!-- Customer Info -->
                <div class="form-group">
                    <label for="custName">Customer Name</label>
                    <input type="text" id="custName" placeholder="Enter customer name">
                </div>
                <div class="form-group">
                    <label for="custPhone">Customer Phone</label>
                    <input type="text" id="custPhone" placeholder="Enter phone number">
                </div>

                <!-- Search Medicine -->
                <div class="search-box">
                    <input type="text" id="searchMedicine" placeholder="🔍 Search medicine by name..." oninput="searchMedicine()">
                </div>

                <!-- Quick Add to Cart -->
                <div class="form-group">
                    <label for="selectMedicine">Select Medicine</label>
                    <select id="selectMedicine">
                        <option value="">-- Select Medicine --</option>
                    </select>
                </div>
                <div class="form-group">
                    <label for="quantity">Quantity</label>
                    <input type="number" id="quantity" placeholder="Enter quantity" min="1" value="1">
                </div>
                
                <button class="btn btn-success" onclick="addToCart()">➕ Add to Cart</button>
                <button class="btn btn-warning" onclick="showCart()">🛒 View Cart</button>

                <!-- Cart Display -->
                <div id="cartDisplay" style="margin-top: 20px;">
                    <h3 style="color: #667eea;">Shopping Cart</h3>
                    <div id="cartItems"></div>
                    <div id="cartTotal" style="text-align: right; font-size: 1.2em; font-weight: bold; margin-top: 15px;"></div>
                </div>

                <button class="btn btn-primary" onclick="generateInvoice()" style="margin-top: 20px;">📄 Generate Invoice</button>
                <button class="btn btn-danger" onclick="clearCart()">🗑️ Clear Cart</button>
            </div>
        </div>

        <!-- Inventory Table -->
        <div class="panel" style="margin-top: 30px;">
            <h2>📊 Medicine Inventory</h2>
            <div class="search-box">
                <input type="text" id="searchInventory" placeholder="🔍 Search inventory by ID, Name, or Manufacturer..." oninput="filterInventory()">
            </div>
            <div class="inventory-table">
                <table id="inventoryTable">
                    <thead>
                        <tr>
                            <th>ID</th>
                            <th>Name</th>
                            <th>Generic</th>
                            <th>Manufacturer</th>
                            <th>Category</th>
                            <th>Price (৳)</th>
                            <th>Stock</th>
                            <th>Expiry</th>
                            <th>Actions</th>
                        </tr>
                    </thead>
                    <tbody id="inventoryBody">
                        <!-- Inventory rows will be inserted here -->
                    </tbody>
                </table>
            </div>
        </div>

        <!-- Invoice Display -->
        <div class="invoice" id="invoiceDisplay">
            <div class="invoice-header">
                <h2>🏥 MediCare Pharmacy</h2>
                <p>Invoice #<span id="invoiceNo"></span></p>
                <p>Date: <span id="invoiceDate"></span></p>
            </div>
            <div class="invoice-details">
                <p><strong>Customer:</strong> <span id="invoiceCustName"></span></p>
                <p><strong>Phone:</strong> <span id="invoiceCustPhone"></span></p>
            </div>
            <table class="invoice-table">
                <thead>
                    <tr>
                        <th>Medicine</th>
                        <th>Price</th>
                        <th>Qty</th>
                        <th>Subtotal</th>
                    </tr>
                </thead>
                <tbody id="invoiceItems">
                </tbody>
            </table>
            <div class="invoice-total">
                Total: ৳<span id="invoiceTotal"></span>
            </div>
            <div style="text-align: center; margin-top: 30px;">
                <button class="btn btn-primary" onclick="printInvoice()">🖨️ Print Invoice</button>
                <button class="btn btn-danger" onclick="closeInvoice()">❌ Close</button>
            </div>
        </div>
    </div>
    
    <!-- Generic Modal for Confirmations/Inputs -->
    <div class="modal" id="genericModal">
        <div class="modal-content">
            <span class="close-modal" onclick="document.getElementById('genericModal').style.display='none'">&times;</span>
            <h2 id="modalTitle" style="color: #667eea; margin-bottom: 15px;"></h2>
            <p id="modalMessage" style="margin-bottom: 20px;"></p>
            <div id="modalInputContainer" class="form-group" style="display: none;">
                <label id="modalInputLabel"></label>
                <input type="text" id="modalInput" placeholder="">
            </div>
            <div style="text-align: right;">
                <button class="btn btn-primary" id="modalConfirmBtn">Confirm</button>
                <button class="btn btn-danger" onclick="document.getElementById('genericModal').style.display='none'">Cancel</button>
            </div>
        </div>
    </div>


    <script>
        // Define Low Stock Threshold
        const LOW_STOCK_THRESHOLD = 20;

        // --- Custom Alert/Modal Implementation ---

        // Custom Toast Notification (replaces alert)
        function showAlert(message, type = 'success') {
            const container = document.getElementById('toastContainer');
            const toast = document.createElement('div');
            toast.className = `toast toast-${type}`;
            toast.innerHTML = message;

            container.appendChild(toast);

            // Show
            setTimeout(() => {
                toast.classList.add('show');
            }, 10);

            // Hide after 4 seconds
            setTimeout(() => {
                toast.classList.remove('show');
                // Remove from DOM after transition
                setTimeout(() => {
                    container.removeChild(toast);
                }, 500);
            }, 4000);
        }

        // Generic Modal Handler (replaces confirm/prompt for critical actions)
        function showModal(title, message, inputConfig = null, onConfirm) {
            const modal = document.getElementById('genericModal');
            document.getElementById('modalTitle').innerHTML = title;
            document.getElementById('modalMessage').innerHTML = message;
            
            const inputContainer = document.getElementById('modalInputContainer');
            const inputField = document.getElementById('modalInput');
            const inputLabel = document.getElementById('modalInputLabel');

            // Reset input fields
            inputContainer.style.display = 'none';
            inputField.value = '';

            if (inputConfig) {
                inputContainer.style.display = 'block';
                inputLabel.textContent = inputConfig.label || 'Value';
                inputField.type = inputConfig.type || 'text';
                inputField.placeholder = inputConfig.placeholder || '';
            }

            const confirmBtn = document.getElementById('modalConfirmBtn');
            // Clear previous event listener
            confirmBtn.onclick = null;
            confirmBtn.onclick = () => {
                modal.style.display = 'none';
                let result = inputConfig ? inputField.value : true; // Pass input value if present, otherwise true for simple confirmation
                onConfirm(result);
            };

            modal.style.display = 'flex'; // Use flex to center
        }

        // --- OOP Classes ---

        // Medicine Class
        class Medicine {
            constructor(id, name, genericName, manufacturer, price, stock, expiry, category) {
                this.id = id;
                this.name = name;
                this.genericName = genericName;
                this.manufacturer = manufacturer;
                this.price = parseFloat(price);
                this.stock = parseInt(stock);
                this.expiry = expiry;
                this.category = category;
            }

            updateStock(quantity) {
                this.stock += quantity;
            }

            isLowStock() {
                return this.stock < LOW_STOCK_THRESHOLD;
            }

            isExpired() {
                const today = new Date();
                today.setHours(0,0,0,0);
                const expiryDate = new Date(this.expiry);
                expiryDate.setHours(0,0,0,0);
                return expiryDate < today;
            }
        }

        // Customer Class
        class Customer {
            constructor(name, phone) {
                this.name = name;
                this.phone = phone;
                this.cart = [];
            }

            // Adds item or increments quantity if already in cart
            addToCart(medicine, quantity) {
                const existingItem = this.cart.find(item => item.medicine.id === medicine.id);
                if (existingItem) {
                    existingItem.quantity += quantity;
                } else {
                    this.cart.push({ medicine, quantity });
                }
            }
            
            // Removes item by index
            removeFromCart(index) {
                this.cart.splice(index, 1);
            }

            clearCart() {
                this.cart = [];
            }

            getTotalAmount() {
                return this.cart.reduce((total, item) => {
                    return total + (item.medicine.price * item.quantity);
                }, 0);
            }
        }

        // Invoice Class
        class Invoice {
            static invoiceCounter = 1000;
            static totalRevenue = 0;
            static totalMedicinesSold = 0;

            constructor(customer) {
                this.invoiceNo = ++Invoice.invoiceCounter;
                this.customer = customer;
                this.date = new Date().toLocaleDateString('en-BD');
                this.items = [...customer.cart];
                this.totalAmount = customer.getTotalAmount();
            }

            generate() {
                // Update static members
                Invoice.totalRevenue += this.totalAmount;
                this.items.forEach(item => {
                    Invoice.totalMedicinesSold += item.quantity;
                    // Deduct stock directly from the medicine object in the inventory array
                    const medInInventory = inventory.find(m => m.id === item.medicine.id);
                    if (medInInventory) {
                        medInInventory.updateStock(-item.quantity);
                    }
                });
                updateStats();
            }
        }

        // --- Global State ---
        let inventory = [];
        let currentCustomer = null;

        // --- Utility Functions ---

        // Clears the Add Medicine form fields
        function clearMedicineForm() {
            document.getElementById('medID').value = '';
            document.getElementById('medName').value = '';
            document.getElementById('genericName').value = '';
            document.getElementById('manufacturer').value = '';
            document.getElementById('price').value = '';
            document.getElementById('stock').value = '';
            document.getElementById('expiryDate').value = '';
            document.getElementById('category').value = 'Tablet';
        }

        // Updates the dashboard statistics
        function updateStats() {
            const totalMeds = inventory.length;
            const lowStockCount = inventory.filter(m => m.stock < LOW_STOCK_THRESHOLD).length;

            document.getElementById('totalMedicines').textContent = totalMeds;
            document.getElementById('totalSales').textContent = `৳${Invoice.totalRevenue.toFixed(2)}`;
            document.getElementById('medicinesSold').textContent = Invoice.totalMedicinesSold;
            document.getElementById('lowStock').textContent = lowStockCount;

            // Apply visual warning to low stock count
            if (lowStockCount > 0) {
                document.getElementById('lowStock').classList.add('low-stock');
            } else {
                document.getElementById('lowStock').classList.remove('low-stock');
            }
        }

        // Renders the inventory table
        function updateInventoryTable(filteredInventory = inventory) {
            const tbody = document.getElementById('inventoryBody');
            tbody.innerHTML = ''; // Clear existing rows

            // Sort by ID for stability
            filteredInventory.sort((a, b) => a.id.localeCompare(b.id));

            filteredInventory.forEach(med => {
                const row = tbody.insertRow();
                const stockClass = med.isLowStock() ? 'low-stock' : '';
                const expiredClass = med.isExpired() ? 'low-stock' : ''; 

                row.innerHTML = `
                    <td>${med.id}</td>
                    <td><strong class="${expiredClass}">${med.name}</strong></td>
                    <td>${med.genericName}</td>
                    <td>${med.manufacturer}</td>
                    <td>${med.category}</td>
                    <td>৳${med.price.toFixed(2)}</td>
                    <td class="${stockClass}">${med.stock}</td>
                    <td class="${expiredClass}">${med.expiry}</td>
                    <td>
                        <button class="btn btn-warning btn-sm" onclick="editMedicine('${med.id}')">Edit</button>
                        <button class="btn btn-danger btn-sm" onclick="deleteMedicine('${med.id}')">Del</button>
                    </td>
                `;
            });
        }

        // Updates the Select Medicine dropdown
        function updateMedicineSelect() {
            const select = document.getElementById('selectMedicine');
            select.innerHTML = '<option value="">-- Select Medicine --</option>'; // Reset

            // Sort inventory alphabetically by name
            const sortedInventory = [...inventory].sort((a, b) => a.name.localeCompare(b.name));

            sortedInventory.forEach(med => {
                const stockWarning = med.isLowStock() ? ' (LOW STOCK!)' : '';
                const option = document.createElement('option');
                option.value = med.id;
                option.textContent = `${med.name} (${med.stock} in stock)${stockWarning} - ৳${med.price.toFixed(2)}`;
                select.appendChild(option);
            });
        }

        // Initial data loading
        function initData() {
            const initialData = [
                { id: 'MED001', name: 'Napa (500mg)', generic: 'Paracetamol', manufacturer: 'Beximco', price: 2.50, stock: 500, expiry: '2025-12-31', category: 'Tablet' },
                { id: 'MED002', name: 'Seclo (20mg)', generic: 'Omeprazole', manufacturer: 'Square', price: 5.00, stock: 250, expiry: '2026-06-15', category: 'Capsule' },
                { id: 'MED003', name: 'Rivotril (2mg)', generic: 'Clonazepam', manufacturer: 'Roche', price: 30.00, stock: 5, expiry: '2024-11-01', category: 'Tablet' }, // Low stock
                { id: 'MED004', name: 'Amodis Syrup', generic: 'Amoxicillin', manufacturer: 'Renata', price: 120.00, stock: 10, expiry: '2027-01-20', category: 'Syrup' }, // Low stock
                { id: 'MED005', name: 'Tylenol (500mg)', generic: 'Paracetamol', manufacturer: 'J&J', price: 2.00, stock: 1000, expiry: '2027-01-20', category: 'Tablet' },
                { id: 'MED006', name: 'Ceftriaxone Inj', generic: 'Ceftriaxone', manufacturer: 'Incepta', price: 500.00, stock: 15, expiry: '2025-12-31', category: 'Injection' },
            ];

            initialData.forEach(med => {
                const medicine = new Medicine(
                    med.id, med.name, med.generic, med.manufacturer, med.price, med.stock, med.expiry, med.category
                );
                inventory.push(medicine);
            });

            updateInventoryTable();
            updateMedicineSelect();
            updateStats();
        }

        // --- Core Application Logic ---

        // Add Medicine Function
        function addMedicine() {
            const id = document.getElementById('medID').value.trim();
            const name = document.getElementById('medName').value.trim();
            const genericName = document.getElementById('genericName').value.trim();
            const manufacturer = document.getElementById('manufacturer').value.trim();
            const price = document.getElementById('price').value;
            const stock = document.getElementById('stock').value;
            const expiry = document.getElementById('expiryDate').value;
            const category = document.getElementById('category').value;

            if (!id || !name || !price || !stock || !expiry) {
                showAlert('Please fill all required fields!', 'danger');
                return;
            }
            if (inventory.some(m => m.id === id)) {
                showAlert(`Medicine ID ${id} already exists!`, 'danger');
                return;
            }

            const medicine = new Medicine(id, name, genericName, manufacturer, price, stock, expiry, category);
            inventory.push(medicine);
            
            showAlert(`Medicine **${name}** added successfully!`, 'success');
            clearMedicineForm();
            updateInventoryTable();
            updateMedicineSelect();
            updateStats();
        }

        // Generate Random Medicine
        function generateRandomMedicine() {
            const medicines = [
                { name: 'Napa (500mg)', generic: 'Paracetamol', manufacturer: 'Beximco', category: 'Tablet' },
                { name: 'Ace Plus', generic: 'Paracetamol + Caffeine', manufacturer: 'Square', category: 'Tablet' },
                { name: 'Amodis', generic: 'Amoxicillin', manufacturer: 'Renata', category: 'Capsule' },
                { name: 'Fexo', generic: 'Fexofenadine', manufacturer: 'Square', category: 'Tablet' },
                { name: 'Omeprazole', generic: 'Omeprazole', manufacturer: 'Incepta', category: 'Capsule' },
                { name: 'Zolap', generic: 'Alprazolam', manufacturer: 'Drug Intl', category: 'Tablet' }
            ];

            const randomMed = medicines[Math.floor(Math.random() * medicines.length)];
            const randomId = 'MED' + Math.floor(Math.random() * 9999).toString().padStart(4, '0');
            const randomPrice = (Math.random() * 100 + 10).toFixed(2);
            const randomStock = Math.floor(Math.random() * 100) + 20;
            
            const today = new Date();
            const expiryDate = new Date(today.setFullYear(today.getFullYear() + 2));

            document.getElementById('medID').value = randomId;
            document.getElementById('medName').value = randomMed.name;
            document.getElementById('genericName').value = randomMed.generic;
            document.getElementById('manufacturer').value = randomMed.manufacturer;
            document.getElementById('price').value = randomPrice;
            document.getElementById('stock').value = randomStock;
            document.getElementById('expiryDate').value = expiryDate.toISOString().split('T')[0];
            document.getElementById('category').value = randomMed.category;
        }

        // Import from Medex (Simulated)
        function importFromMedex() {
            const loading = document.getElementById('importLoading');
            loading.style.display = 'block';

            // Simulate API call delay
            setTimeout(() => {
                const medexData = [
                    { id: 'MED2001', name: 'Histacin', generic: 'Chlorphenamine', manufacturer: 'Popular Pharma', price: 1.50, stock: 450, category: 'Tablet' },
                    { id: 'MED2002', name: 'Xorim', generic: 'Cefuroxime', manufacturer: 'Incepta', price: 35.00, stock: 80, category: 'Tablet' },
                    { id: 'MED2003', name: 'Ambrox', generic: 'Ambroxol', manufacturer: 'Acme', price: 80.00, stock: 120, category: 'Syrup' },
                    { id: 'MED2004', name: 'Diclofenac', generic: 'Diclofenac Sodium', manufacturer: 'Generic Co.', price: 1.00, stock: 9, category: 'Tablet' }, // Low stock item
                ];
                
                let importCount = 0;
                const today = new Date();

                medexData.forEach(med => {
                    if (!inventory.some(m => m.id === med.id)) { // Prevent duplicate IDs
                        const expiryDate = new Date(today);
                        expiryDate.setFullYear(expiryDate.getFullYear() + 2);
                        
                        const medicine = new Medicine(
                            med.id, med.name, med.generic, med.manufacturer, med.price, med.stock, 
                            expiryDate.toISOString().split('T')[0], med.category
                        );
                        inventory.push(medicine);
                        importCount++;
                    }
                });

                loading.style.display = 'none';
                showAlert(`Successfully imported ${importCount} new medicines!`, 'success');
                updateInventoryTable();
                updateMedicineSelect();
                updateStats();
            }, 2000);
        }

        // Add to Cart
        function addToCart() {
            const custName = document.getElementById('custName').value.trim();
            const custPhone = document.getElementById('custPhone').value.trim();
            const selectedMedId = document.getElementById('selectMedicine').value;
            const quantity = parseInt(document.getElementById('quantity').value);

            if (!custName || !custPhone) {
                showAlert('Please enter customer details!', 'danger');
                return;
            }

            if (!selectedMedId) {
                showAlert('Please select a medicine!', 'danger');
                return;
            }

            if (isNaN(quantity) || quantity <= 0) {
                showAlert('Please enter a valid quantity.', 'danger');
                return;
            }

            if (!currentCustomer || currentCustomer.name !== custName || currentCustomer.phone !== custPhone) {
                currentCustomer = new Customer(custName, custPhone);
            }

            const medicine = inventory.find(m => m.id === selectedMedId);
            
            if (!medicine) {
                showAlert('Medicine not found in inventory!', 'danger');
                return;
            }
            if (medicine.isExpired()) {
                 showAlert(`**${medicine.name}** is expired! Cannot sell.`, 'danger');
                 return;
            }
            
            // Calculate total quantity requested (existing in cart + new quantity)
            const cartItem = currentCustomer.cart.find(item => item.medicine.id === medicine.id);
            const currentCartQty = cartItem ? cartItem.quantity : 0;
            const totalRequestedQty = currentCartQty + quantity;

            if (totalRequestedQty > medicine.stock) {
                showAlert(`Insufficient stock! Available: ${medicine.stock}. Already in cart: ${currentCartQty}.`, 'danger');
                return;
            }

            currentCustomer.addToCart(medicine, quantity);
            showAlert(`Added ${quantity}x **${medicine.name}** to cart!`, 'success');
            document.getElementById('quantity').value = 1; // Reset quantity input
            updateCartDisplay();
        }

        // Update Cart Display
        function updateCartDisplay() {
            if (!currentCustomer || currentCustomer.cart.length === 0) {
                document.getElementById('cartItems').innerHTML = '<p style="color: #666; font-style: italic;">Cart is empty. Add items from the selection above.</p>';
                document.getElementById('cartTotal').innerHTML = '';
                return;
            }

            let html = '';
            currentCustomer.cart.forEach((item, index) => {
                const subtotal = item.medicine.price * item.quantity;
                html += `
                    <div class="cart-item">
                        <div class="cart-item-info">
                            <h4>${item.medicine.name} (x${item.quantity})</h4>
                            <p>Price: ৳${item.medicine.price.toFixed(2)} | Subtotal: ৳${subtotal.toFixed(2)}</p>
                        </div>
                        <button class="remove-btn" onclick="removeFromCart(${index})">Remove</button>
                    </div>
                `;
            });

            document.getElementById('cartItems').innerHTML = html;
            document.getElementById('cartTotal').innerHTML = `Total: ৳${currentCustomer.getTotalAmount().toFixed(2)}`;
        }

        // Remove from Cart
        function removeFromCart(index) {
            const removedItem = currentCustomer.cart[index];
            currentCustomer.removeFromCart(index);
            showAlert(`Removed **${removedItem.medicine.name}** from cart.`, 'warning');
            updateCartDisplay();
        }

        // Clear Cart (uses modal for confirmation)
        function clearCart() {
            if (!currentCustomer || currentCustomer.cart.length === 0) {
                showAlert('Cart is already empty!', 'warning');
                return;
            }
            
            showModal(
                'Confirm Clear Cart',
                'Are you sure you want to clear the current customer\'s shopping cart?',
                null,
                (confirmed) => {
                    if (confirmed) {
                        currentCustomer.clearCart();
                        updateCartDisplay();
                        showAlert('Cart cleared!', 'success');
                    }
                }
            );
        }

        // Generate Invoice
        function generateInvoice() {
            if (!currentCustomer || currentCustomer.cart.length === 0) {
                showAlert('Cart is empty! Cannot generate invoice.', 'danger');
                return;
            }

            const invoice = new Invoice(currentCustomer);
            
            // 1. Finalize the transaction (updates stock and stats)
            invoice.generate();

            // 2. Display invoice details
            document.getElementById('invoiceNo').textContent = invoice.invoiceNo;
            document.getElementById('invoiceDate').textContent = invoice.date;
            document.getElementById('invoiceCustName').textContent = invoice.customer.name;
            document.getElementById('invoiceCustPhone').textContent = invoice.customer.phone;

            let itemsHtml = '';
            invoice.items.forEach(item => {
                const subtotal = item.medicine.price * item.quantity;
                itemsHtml += `
                    <tr>
                        <td>${item.medicine.name}</td>
                        <td>৳${item.medicine.price.toFixed(2)}</td>
                        <td>${item.quantity}</td>
                        <td>৳${subtotal.toFixed(2)}</td>
                    </tr>
                `;
            });

            document.getElementById('invoiceItems').innerHTML = itemsHtml;
            document.getElementById('invoiceTotal').textContent = invoice.totalAmount.toFixed(2);

            // 3. Clear cart and UI updates
            currentCustomer.clearCart();
            updateCartDisplay();
            updateInventoryTable();
            updateMedicineSelect(); // Stock counts are updated
            showAlert(`Invoice **#${invoice.invoiceNo}** generated successfully! Total: ৳${invoice.totalAmount.toFixed(2)}`, 'success');

            // 4. Show invoice panel and hide main content
            document.querySelector('.main-content').style.display = 'none';
            document.getElementById('invoiceDisplay').style.display = 'block';
            document.querySelector('.stats-container').style.display = 'none';
            document.querySelector('.panel:last-of-type').style.display = 'none'; // Hide the inventory panel
        }

        function closeInvoice() {
            document.getElementById('invoiceDisplay').style.display = 'none';
            document.querySelector('.main-content').style.display = 'grid'; // Restore grid layout
            document.querySelector('.stats-container').style.display = 'grid';
            document.querySelector('.panel:last-of-type').style.display = 'block'; // Restore inventory panel
        }

        function printInvoice() {
            showAlert('Simulating printing invoice to PDF/Thermal printer...', 'warning');
        }

        // --- Inventory Management Actions (Using Modal) ---

        function editMedicine(id) {
            const med = inventory.find(m => m.id === id);
            if (!med) {
                showAlert('Medicine not found for editing.', 'danger');
                return;
            }

            showModal(
                'Edit Stock Quantity',
                `Update stock for **${med.name}** (Current: ${med.stock}).`,
                { label: 'New Stock Quantity', type: 'number', placeholder: med.stock },
                (newStockStr) => {
                    const newStock = parseInt(newStockStr);
                    if (!isNaN(newStock) && newStock >= 0) {
                        med.stock = newStock;
                        showAlert(`Stock for **${med.name}** updated to ${newStock}`, 'success');
                        updateInventoryTable();
                        updateMedicineSelect();
                        updateStats();
                    } else {
                        showAlert('Invalid stock quantity entered. Stock not updated.', 'danger');
                    }
                }
            );
        }

        function deleteMedicine(id) {
            const medIndex = inventory.findIndex(m => m.id === id);
            if (medIndex > -1) {
                const medName = inventory[medIndex].name;
                showModal(
                    'Confirm Deletion',
                    `Are you sure you want to permanently delete **${medName}** from the inventory? This cannot be undone.`,
                    null, 
                    (confirmed) => {
                        if (confirmed) {
                            inventory.splice(medIndex, 1);
                            showAlert(`**${medName}** deleted successfully.`, 'danger');
                            updateInventoryTable();
                            updateMedicineSelect();
                            updateStats();
                        }
                    }
                );
            } else {
                showAlert('Medicine not found for deletion.', 'danger');
            }
        }

        // --- Search and Filter Functions ---

        // Filter Inventory Table by text input
        function filterInventory() {
            const searchTerm = document.getElementById('searchInventory').value.toLowerCase();
            const filtered = inventory.filter(med =>
                med.name.toLowerCase().includes(searchTerm) ||
                med.genericName.toLowerCase().includes(searchTerm) ||
                med.manufacturer.toLowerCase().includes(searchTerm) ||
                med.id.toLowerCase().includes(searchTerm) ||
                med.category.toLowerCase().includes(searchTerm)
            );
            updateInventoryTable(filtered);
        }

        // Search Medicine (for the Sales panel select box)
        function searchMedicine() {
            const searchTerm = document.getElementById('searchMedicine').value.toLowerCase();
            const select = document.getElementById('selectMedicine');
            select.innerHTML = '<option value="">-- Select Medicine --</option>'; // Reset

            if (searchTerm.length < 2) {
                updateMedicineSelect(); // Restore full list if search is too short
                return;
            }

            const filtered = inventory.filter(med =>
                med.name.toLowerCase().includes(searchTerm) ||
                med.genericName.toLowerCase().includes(searchTerm) ||
                med.id.toLowerCase().includes(searchTerm)
            );

            filtered.forEach(med => {
                const stockWarning = med.isLowStock() ? ' (LOW STOCK!)' : '';
                const option = document.createElement('option');
                option.value = med.id;
                option.textContent = `${med.name} (${med.stock} in stock)${stockWarning} - ৳${med.price.toFixed(2)}`;
                select.appendChild(option);
            });
        }

        // Placeholder for showCart (for mobile usability)
        function showCart() {
            // Scroll to cart display for better visibility on small screens
            document.getElementById('cartDisplay').scrollIntoView({ behavior: 'smooth' });
        }

        // Initial setup call on window load
        window.onload = initData;

    </script>
</body>
</html>

