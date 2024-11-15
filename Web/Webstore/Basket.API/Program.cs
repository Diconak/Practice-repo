using Basket.API.Repository;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.

builder.Services.AddControllers();
// Learn more about configuring Swagger/OpenAPI at https://aka.ms/aspnetcore/swashbuckle
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();
//Radili smo dependency injection za interface
builder.Services.AddScoped<IBasketRepository, BasketRepository>();
builder.Services.AddControllers();

//Ovo nam povezuje nas servis, i konfigurise ga, u nasem slucaju, povezuje nas servis na port gde nam se nalazi redis
builder.Services.AddStackExchangeRedisCache(
    opts => {
        opts.Configuration = builder.Configuration.GetValue<string>("CacheSettings:ConnectionString");
    }
    );

var app = builder.Build();

// Configure the HTTP request pipeline.
if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

app.UseAuthorization();

app.MapControllers();

app.Run();
