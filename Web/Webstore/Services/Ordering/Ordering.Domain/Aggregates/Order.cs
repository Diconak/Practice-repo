﻿using Ordering.Domain.Common;
using Ordering.Domain.Entities;
using Ordering.Domain.Value_Objects;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ordering.Domain.Aggregates
{
    public class Order : AggregateRoot
    {
        public string BuyerId { get; private set; }
        public string BuyerUsername { get; private set; }
        public DateTime OrderDate { get; private set; }
        public Address Address { get; private set; }

        private readonly List<OrderItem> _orderItems = new List<OrderItem>();
        public IReadOnlyCollection<OrderItem> OrderItems => _orderItems;

        public Order(string buyerId, string buyerUsername, Address address)
        {
            BuyerId = buyerId ?? throw new ArgumentNullException(nameof(buyerId));
            BuyerUsername = buyerUsername ?? throw new ArgumentNullException(nameof(buyerUsername));
            Address = address ?? throw new ArgumentNullException(nameof(address));
            OrderDate = DateTime.Now;
        }
        public Order(int id, string buyerId, string buyerUsername, Address address) : this(buyerId, buyerUsername, address)
        {
            Id = id;
        }

        public Order(int id)
        {
            Id = id;
        }

        public void AddOrderItem(string productName, string productId, string pictureUrl, decimal price, int units) {
            var existingOrderItem = OrderItems.Where(o => o.ProductId == productId).SingleOrDefault();
            if (existingOrderItem == null)
            {
                var orderItem = new OrderItem(productName, productId, pictureUrl, price, units);
                _orderItems.Add(orderItem);

            }
            else { 
                existingOrderItem.AddUnits(units);
            }
        }

        public decimal GetTotal() => OrderItems.Sum(o => o.TotalPrice());
    }
}